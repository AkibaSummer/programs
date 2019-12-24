// g++ ./Lab02.cc -o ./1 -lsfml-graphics -lsfml-window -lsfml-system -O3
#include <assert.h>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#define NUM_PLANETS 1000
#define INITIAL_SPEED
#define FPS 60
#define TIME_PER_ITER 1
// #define TIME_PER_ITER 0.1
using std::vector;
const double eps = 1e-9;
const double min_dist = 1;
const double G = 1e-3; /* 万有引力常数 */

class Vector {
 public:
  double x, y, z;
  Vector() : x(0), y(0), z(0) {}
  Vector(double x1, double y1, double z1) : x(x1), y(y1), z(z1) {}
  Vector(const Vector &v) : x(v.x), y(v.y), z(v.z) {}
  ~Vector(){};
  void operator=(const Vector &v);
  Vector operator+(const Vector &v);
  Vector operator-(const Vector &v);
  Vector operator/(const Vector &v);
  Vector operator*(const Vector &v);
  Vector operator+(double f);
  Vector operator-(double f);
  Vector operator/(double f);
  Vector operator*(double f);
  double dot(const Vector &v);
  double length();
  void normalize();
  Vector crossProduct(const Vector &v);
  friend std::ostream &operator<<(std::ostream &cout, Vector v);
};
void Vector::operator=(const Vector &v) {
  x = v.x;
  y = v.y;
  z = v.z;
}
Vector Vector::operator+(const Vector &v) {
  return Vector(x + v.x, y + v.y, z + v.z);
}
Vector Vector::operator-(const Vector &v) {
  return Vector(x - v.x, y - v.y, z - v.z);
}
Vector Vector::operator/(const Vector &v) {
  if (fabsf(v.x) <= eps || fabsf(v.y) <= eps || fabsf(v.z) <= eps) {
    std::cerr << "Divide by zero error." << std::endl;
    return *this;
  }
  return Vector(x / v.x, y / v.y, z / v.z);
}
Vector Vector::operator*(const Vector &v) {
  return Vector(x * v.x, y * v.y, z * v.z);
}
Vector Vector::operator+(double f) { return Vector(x + f, y + f, z + f); }
Vector Vector::operator-(double f) { return Vector(x - f, y - f, z - f); }
Vector Vector::operator/(double f) {
  if (fabsf(f) < eps) {
    std::cerr << "Divide by zero error." << std::endl;
    return *this;
  }
  return Vector(x / f, y / f, z / f);
}
Vector Vector::operator*(double f) { return Vector(x * f, y * f, z * f); }
double Vector::dot(const Vector &v) { return x * v.x + y * v.y + z * v.z; }
double Vector::length() { return sqrtf(dot(*this)); }
void Vector::normalize() {
  double len = length();
  if (len < eps) len = 1;
  len = 1 / len;

  x *= len;
  y *= len;
  z *= len;
}
Vector Vector::crossProduct(const Vector &v) {
  return Vector(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
std::ostream &operator<<(std::ostream &cout, Vector v) {
  cout << v.x << " " << v.y << " " << v.z << " ";
  return cout;
}
struct Tree {
  int son[8] = {0};
  int bob;
  Vector center;
  double mass;
  Tree() {
    bob = 0;
    center = Vector();
    mass = 0;
  }
};

struct Planet {
  Vector pos;  // 位置
  Vector v;    // 速度
  Vector a;    // 加速度
  double m;    // 质量
} planet[NUM_PLANETS + 1];
bool nome[NUM_PLANETS + 1];  // 已经飞出地图的点

void insertNode(int r, int v, double sx, double sy, double sz, double size,
                vector<Tree> &tree) {
  double mass = 0;
  Vector center = Vector();
  size /= 2;
  int cx = planet[v].pos.x > sx + size, cy = planet[v].pos.y > sy + size,
      cz = planet[v].pos.z > sz + size, index = (cx << 2) | (cy << 1) | cz;
  assert(index < 8);
  if (!tree[r].son[0]) {
    if (tree[r].bob) {
      for (int i = 0; i < 8; i++) {
        tree.emplace_back(Tree());
        tree[r].son[i] = tree.size() - 1;
      }
      int bx = planet[tree[r].bob].pos.x > sx + size,
          by = planet[tree[r].bob].pos.y > sy + size,
          bz = planet[tree[r].bob].pos.z > sz + size,
          inbex = (bx << 2) | (by << 1) | bz;
      insertNode(tree[r].son[inbex], tree[r].bob, sx + bx * size,
                 sy + by * size, sz + bz * size, size, tree);
      insertNode(tree[r].son[index], v, sx + cx * size, sy + cy * size,
                 sz + cz * size, size, tree);
      tree[r].bob = 0;
    } else {
      tree[r].bob = v;
      mass = planet[v].m;
      center = planet[v].pos;
    }
  } else {
    insertNode(tree[r].son[index], v, sx + cx * size, sy + cy * size,
               sz + cz * size, size, tree);
  }

  //合并节点

  if (tree[r].son[0]) {
    for (int i = 0; i < 8; i++) {
      Tree &n = tree[tree[r].son[i]];
      if (n.mass) {
        center = (center * mass + n.center * n.mass) / (mass + n.mass);
        mass += n.mass;
      }
    }
  }
  tree[r].center = center;
  tree[r].mass = mass;
}

void updateNode(int r, int v, double size, vector<Tree> &tree) {
  if (tree[r].bob == v) return;
  if (tree[r].bob) {
    assert(tree[r].bob != 0);
    double length = (planet[tree[r].bob].pos - planet[v].pos).length();
    if (length < 1) return;
    Vector F = planet[tree[r].bob].pos - planet[v].pos;
    F.normalize();
    F = F * (G * planet[tree[r].bob].m * planet[v].m / length / length);
    planet[v].a = planet[v].a - F / planet[v].m;
    return;
  }
  if (tree[r].son[0]) {
    if (size / (tree[r].center - planet[v].pos).length() > 0.5) {
      for (int i = 0; i < 8; i++) {
        updateNode(tree[r].son[i], v, size / 2, tree);
      }
    } else {
      double length = (planet[tree[r].bob].pos - planet[v].pos).length();
      if (length < 1) return;
      Vector F = planet[tree[r].bob].pos - planet[v].pos;
      F.normalize();
      F = F * (G * planet[tree[r].bob].m * planet[v].m / length / length);
      planet[v].a = planet[v].a - F / planet[v].m;
      return;
    }
  }
}

int main() {
  int n = NUM_PLANETS;
  std::default_random_engine engine;
  std::uniform_real_distribution<double> unifx(-1000., 1000.);
  std::normal_distribution<double> unify(0., 100.);
  std::uniform_real_distribution<double> unifz(-1000., 1000.);
  std::uniform_real_distribution<double> unifa(0, 2 * 3.1415926);
#ifdef INITIAL_SPEED
  std::uniform_real_distribution<double> univx(-20. / TIME_PER_ITER,
                                               20. / TIME_PER_ITER);
  std::uniform_real_distribution<double> univy(-3. / TIME_PER_ITER,
                                               3. / TIME_PER_ITER);
  std::uniform_real_distribution<double> univz(-20. / TIME_PER_ITER,
                                               20. / TIME_PER_ITER);
#endif
  std::normal_distribution<double> norm(10000., 5000.);

  for (int i = 1; i <= n; i++) {
    /*
    planet[i].pos.x = unifx(engine);
    planet[i].pos.z = unifz(engine);
    */
    double r = unifx(engine);
    r = r + (r > 0 ? 300 : -300);
    double a = unifa(engine);
    planet[i].pos.x = r * sin(a);
    planet[i].pos.z = r * cos(a);
    planet[i].pos.y = unify(engine);
#ifdef INITIAL_SPEED
    /*
    planet[i].v.x = univx(engine);
    planet[i].v.z = univz(engine);
    */
    double l = univx(engine);
    planet[i].v.x = l * sin(a + 3.1415926 / 2);
    planet[i].v.z = l * cos(a + 3.1415926 / 2);
    planet[i].v.y = univy(engine);
#endif
    planet[i].m =
        abs(norm(engine)) + 100.;  // in case negative if you are so lucky
  }

  // planet[0].m = 1200000;
  // planet[0].pos = Vector(0, 0, 0);  // a big sun

  // planet[1].m = 1200000;
  // planet[1].pos = Vector(0, 0, 0);
  // planet[1].v = Vector(0, 0, 0);

  vector<Tree> tree;

  tree.emplace_back();

  sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window");
  window.setFramerateLimit(FPS);
  for (int it = 0; window.isOpen(); it++) {  // calculate for every iteration
    sf::Event event;
    while (window.pollEvent(event)) {
      // Close window: exit
      if (event.type == sf::Event::Closed) window.close();
    }

    tree.clear();
    tree.emplace_back();
    for (int i = 1; i <= n; i++) {
      if (!nome[i]) {
        insertNode(0, i, -3200., -3200., -3200., 6400., tree);
      }
    }

    // change speed
    for (int i = 1; i <= n; i++) {
      if (!nome[i]) {
        planet[i].a = Vector();
        updateNode(0, i, 6400, tree);
      }
    }
    for (int i = 1; i <= n; i++)
      if (!nome[i]) {
        planet[i].v = planet[i].v - planet[i].a * TIME_PER_ITER;
        // std::cerr<<planet[i].a<<' '<<planet[i].v<<std::endl;
      }
    // change position
    for (int i = 1; i <= n; i++)
      if (!nome[i]) {
        planet[i].pos = planet[i].pos + planet[i].v * TIME_PER_ITER;

        if (abs(planet[i].pos.x) >= 3200. || abs(planet[i].pos.y) >= 3200. ||
            abs(planet[i].pos.z) >= 3200.) {
          // skip if it flies out of space.
          // planet[i].pos.x=std::min(3200.-abs(univy(engine)),planet[i].pos.x);
          // planet[i].pos.y=std::min(3200.-abs(univy(engine)),planet[i].pos.y);
          // planet[i].pos.z=std::min(3200.-abs(univy(engine)),planet[i].pos.z);
          // planet[i].pos.x=std::max(-3200.+abs(univy(engine)),planet[i].pos.x);
          // planet[i].pos.y=std::max(-3200.+abs(univy(engine)),planet[i].pos.y);
          // planet[i].pos.z=std::max(-3200.+abs(univy(engine)),planet[i].pos.z);
          planet[i].pos.x += planet[i].pos.x > 3200 ? -6400 : 0;
          planet[i].pos.y += planet[i].pos.y > 3200 ? -6400 : 0;
          planet[i].pos.z += planet[i].pos.z > 3200 ? -6400 : 0;
          planet[i].pos.x += planet[i].pos.x < -3200 ? 6400 : 0;
          planet[i].pos.y += planet[i].pos.y < -3200 ? 6400 : 0;
          planet[i].pos.z += planet[i].pos.z < -3200 ? 6400 : 0;
          planet[i].v = Vector();
          // nome[i] = true;
          // planet[i].v = Vector();
        }
      }
    std::cout << "Time = " << it << ", pos: " << planet[1].pos << std::endl;

    window.clear();
    for (int i = 0; i <= n; i++) {
      if (!nome[i]) {
        sf::CircleShape circle;
        circle.setFillColor(sf::Color(
            255, 255, 255,
            std::min(std::max((planet[i].pos.y + 3200) * 255 / 6400, 0.),
                     255.)));
        // circle.setFillColor(sf::Color::White);

        circle.setRadius(sqrt(planet[i].m) * 2 / 100);
        circle.setPosition(
            {planet[i].pos.x * 1000 / 6400 + 500 - circle.getRadius(),
             planet[i].pos.z * 1000 / 6400 + 500 - circle.getRadius()});
        circle.setOutlineColor(sf::Color(
            0, 0, 255,
            std::min(std::max((planet[i].pos.y + 3200) * 255 / 6400, 0.),
                     255.)));
        circle.setOutlineColor(sf::Color::Blue);
        circle.setOutlineThickness(1);
        window.draw(circle);
      }
    }
    window.display();
  }
  return 0;
}
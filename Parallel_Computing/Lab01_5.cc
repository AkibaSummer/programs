#include <bits/stdc++.h>
#include <mpich/mpi.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
using namespace std;
using namespace boost::multiprecision;

string PI = "3.141592653589793238462643383279502884197169399375105820974944";
#define PRECISION 50
typedef number<cpp_bin_float<PRECISION> > pi_type;

pi_type f() {
  pi_type a = pi_type(rand()) / RAND_MAX;
  return (pi_type(4) / (pi_type(1) + a * a));
}

pi_type pi_exact;

int main(int argc, char *argv[]) {
  pi_exact = pi_type(PI.c_str());

  int myid, numprocs, namelen;
  double startwtime = 0.0, endwtime;
  char processor_name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Get_processor_name(processor_name, &namelen);

  fprintf(stdout, "Process %d of %d is on %s\n", myid + 1, numprocs,
          processor_name);
  fflush(stdout);

  int n, i;
  n = 10000000;  // the number of iterations
  if (myid == 0) {
    startwtime = MPI_Wtime();
  }
  MPI_Bcast(&n, sizeof(n), MPI_BYTE, 0, MPI_COMM_WORLD);

  srand(time(0));
  
  pi_type pi = 0, sum = 0, x, h;
  h = pi_type(1) / n;
  for (i = myid + 1; i <= n; i += numprocs) {
    x = h * (pi_type(i) - 0.5);
    sum += f();
  }

  sum = sum / n;

  pi_type *in = nullptr;
  if (myid == 0) {
    in = new pi_type[numprocs];
  }
  MPI_Gather(&sum, sizeof(sum), MPI_BYTE, in, sizeof(sum), MPI_BYTE, 0,
             MPI_COMM_WORLD);

  if (myid == 0) {
    for (int i = 0; i < numprocs; i++) {
      pi += in[i];
    }
    cout << defaultfloat << setprecision(PRECISION);
    cout << "pi is approximately " << pi << endl;
    cout << scientific << setprecision(5);
    cout << "Error is " << boost::multiprecision::fabs(pi - pi_exact) << endl;
    endwtime = MPI_Wtime();
    cout << "wall clock time = " << endwtime - startwtime << endl;
  }

  MPI_Finalize();
  return 0;
}
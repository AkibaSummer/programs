package projec7;

public class Octagon implements Cloneable,Comparable<Octagon> {
	double side;
	public Octagon() {
		super();
		side=0;
	}
	public Octagon(double length) {
		super();
		this.side = length;
	}
	public double getLength() {
		return side;
	}
	public void setLength(double length) {
		this.side = length;
	}
	@Override
	public Octagon clone() {
		return new Octagon(side);
	}
	@Override
	public int compareTo(Octagon o) {
		return Double.compare(side, o.side);
	}
	public double getArea() {
		return (2+4/Math.sqrt(2))*side*side;
	}
	public double getPerimeter() {
		return 8*side;
	}
}

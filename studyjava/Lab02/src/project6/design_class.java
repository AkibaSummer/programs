package project6;

class GeometricObject {
	private String color = "white";
	private boolean filled;
	private java.util.Date dateCreated;

	public GeometricObject(){
		dateCreated = new java.util.Date();
	}

	public GeometricObject(String color, boolean filled){
		dateCreated = new java.util.Date();
		this.color = color;
		this.filled= filled;
	}

	public String getColor(){
		return color;
	}
	public void setColor(String color){
		this.color = color;
	}

	public boolean isFilled(){
		return filled;
	}

	public void setFilied(boolean filled){
		this.filled = filled;
	}

	public java.util.Date getDateCreated() {
		return dateCreated;
	}

	public String toString() {
		return "created on " + dateCreated + "\ncolor: " + color + " and filled: "+ filled;
	}
}

class Triangle extends GeometricObject{
	double side1=1.0,side2=1.0,side3=1.0;
	public Triangle(){

	}
	public Triangle (double s1,double s2,double s3){
		side1=s1;
		side2=s2;
		side3=s3;
	}
	public double getSide1() {
		return side1;
	}
	public double getSide2() {
		return side2;
	}
	public double getSide3() {
		return side3;
	}
	public double getArea() {
		double p=side1+side2+side3;
		return Math.sqrt(p*(p-side1)*(p-side2)*(p-side3));
	}
	public double getPerimeter() {
		return side1+side2+side3;
	}

	public String toString() {
		return  super.toString() + "\nTriangle: side1 = " + side1 + " side2 = " + side2 +  " side3 = " + side3;
	}
}

public class design_class {
	public static void main(String args[]) {
		Triangle triangle=new Triangle(1,1.5,1);
		triangle.setColor("yellow");
		triangle.setFilied(true);
		System.out.println(triangle.toString());
	}
}

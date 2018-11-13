package project4;

class Rectangle{
	private double width,height;
	private static String color="white";
	public Rectangle() {
		this.width = 1;
		this.height = 1;
	}
	public Rectangle(double width, double height) {
		this.width = width;
		this.height = height;
	}
	public double getWidth() {
		return width;
	}
	public void setWidth(double width) {
		this.width = width;
	}
	public double getHeight() {
		return height;
	}
	public void setHeight(double height) {
		this.height = height;
	}
	public static String getColor() {
		return color;
	}
	public static void setColor(String color) {
		Rectangle.color = color;
	}
	public double getArea() {
		return width*height;
	}
	public double getPerimeter() {
		return (width+height)*2;
	}
	public void show() {
		System.out.println("I'm a "+this.getClass().getSimpleName()+".");
		System.out.println("My width is "+width+", my height is "+height+".");
		System.out.println("My area is "+getArea()+", my perimeter is "+getPerimeter()+".");
		System.out.println("My color is "+color+".");
		System.out.println();
	}
}

class Time{
	int hour,minute,second;
	public Time() {
		this(System.currentTimeMillis());
	}
	public Time(long mill) {
		second=(int)(mill/1000%60);
		minute=(int)(mill/1000/60%60);
		hour=(int)(mill/1000/60/60%24);
	}
	public void show() {
		System.out.println("My time is "+hour+":"+minute+":"+second);
	}
}

public class Design_Classes {
	public static void main(String args[]) {
		Rectangle rec1=new Rectangle(4,40);
		Rectangle rec2=new Rectangle(3.5,35.9);
		Rectangle.setColor("Red");
		rec1.show();rec2.show();
		
		Time nowtime=new Time();
		Time times=new Time(555550000);
		nowtime.show();
		times.show();
	}
}

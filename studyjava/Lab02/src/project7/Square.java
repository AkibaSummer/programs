package project7;

public class Square extends GeometricObject implements Colorable{
	int width,height;

	public Square() {
		width=height=0;
	}

	public Square(int width,int height) {
		this.width=width;
		this.height=height;
	}

	public int getWidth() {
		return width;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public int getHeight() {
		return height;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	@Override
	public void howToColor() {
		System.out.println("howToColor: Use pen to color it");
	}

	public int getArea() {
		return width*height;
	}

	public int getPerimeter() {
		return width+height+width+height;
	}
}
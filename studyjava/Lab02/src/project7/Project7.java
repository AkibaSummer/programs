package project7;

public class Project7 {
	public static void main(String args[]) {
		GeometricObject geometric[]=new GeometricObject[5];
		for (int i=0;i<5;i++) {
			geometric[i]=new Square();
		}
		for (int i=0;i<5;i++) {
			if (geometric[i] instanceof Colorable) {
				((Colorable)geometric[i]).howToColor();
			}
		}	
		
		Octagon octagon = new Octagon(5);
		System.out.println("Area = " + octagon.getArea());
		System.out.println("Perimeter = " + octagon.getPerimeter());
		Octagon cloned = octagon.clone();
		System.out.println("Compare two Octagon = " + octagon.compareTo(cloned));
	}
}

package U7T3; 
class Thread1 implements Runnable{
	public void run() {
		for (char i='a';i<='z';i++) {
			System.out.println(i);
		}
	}
}

class Thread2 extends Thread{
	public void run() {
		for (int i=1;i<=26;i++) {
			System.out.println(i);
		}
	}
}

public class U7T3 extends Thread{
	public static void main(String args[]) {
		(new Thread(new Thread1())).start();
		(new Thread2()).start();
	}
}

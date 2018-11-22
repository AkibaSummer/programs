package U7T4;
class Thread1 extends Thread{
	public void run() {
		for (char i='a';i<='z';i++) {
			System.out.println(i);
			if (i=='o') yield();
		}
	}
}

class Thread2 implements Runnable{
	Thread1 t1;
	public Thread2(Thread1 t1) {
		this.t1=t1;
	}
	public void run() {
		for (int i=1;i<=26;i++) {
			System.out.println(i);
			try {
			    if (i==20)t1.join();
			}
			catch (InterruptedException ex) {
				System.out.println(ex.getMessage());
			}
		}
	}
}

public class U7T4 {
	public static void main(String args[]) {
		Thread1 t1 = new Thread1();
		Thread2 t2 = new Thread2(t1);
		t1.start();
		(new Thread(t2)).start();
	}
}

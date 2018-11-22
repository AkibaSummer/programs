package U7T5;
public class U7T5 extends Thread{
	private int x=0;
	synchronized void Thread1(){
		try {
			sleep(1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		++x;
		System.out.println("++x="+x);	}
	synchronized void Thread2(){
		--x;
		System.out.println("--x="+x);	}
	public static void main(String args[]) {
		U7T5 u7t5=new U7T5();
		for (int i=1;i<=20;i++) {
			u7t5.Thread1();
			u7t5.Thread2();
		}
	}
}
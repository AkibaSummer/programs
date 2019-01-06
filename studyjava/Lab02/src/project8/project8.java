package project8;
import java.util.Random;
public class project8 {
	public static class Judger extends Thread{
		public class Bean {
			public char c;
			public int sleeptime;
			public boolean flag = false;
		}
		public class Worker implements Runnable{
			private Thread t;
			private Bean bean;
			public Worker(Bean bean) {
				this.bean=bean;
			}
			@Override
			public void run() {
				try {
					Thread.sleep(bean.sleeptime=new Random().nextInt(500));
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				synchronized (bean) {
					bean.c=(char) (new Random().nextInt(26)+'a');
					bean.flag=true;
					bean.notify();
				}
			}	

			public void start() {
				if (t==null) {
					t = new Thread(this);
					t.start();
				}
			}
		}
		@Override
		public void run() {
			int suma=0,sumb=0;
			System.out.println("┌──────────┬────────────────────────────────┬────────────────────────────────┐");
			System.out.println("│          │             Thread A           │             Thread B           │");
			System.out.println("│          ├──────────┬──────────┬──────────┼──────────┬──────────┬──────────┤");
			System.out.println("│   Round  │     Sleep│    Random│    Points│     Sleep│    Random│    Points│");
			System.out.println("│          │      time│ character│  obtained│      time│ character│  obtained│");
			for (int round=1;round<=10;round++) {
				System.out.println("├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤");
				Bean bean1=new Bean();
				Bean bean2=new Bean();
				Worker worker1=new Worker(bean1);
				Worker worker2=new Worker(bean2);
				worker1.start();
				worker2.start();
				synchronized (bean1) {
					if (!bean1.flag) {
						try {
							bean1.wait();
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}
				synchronized (bean2) {
					if (!bean2.flag) {
						try {
							bean2.wait();
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}
				int pointa=0,pointb=0;
				if (bean1.c>bean2.c) {
					pointa=2;
				}
				else if (bean1.c<bean2.c) {
					pointb=2;
				}
				else {
					pointa=1;
					pointb=1;
				}
				System.out.printf("│%10d│%10d│%10c│%10d│%10d│%10c│%10d│\n", round,bean1.sleeptime,
						bean1.c,pointa,bean2.sleeptime,bean2.c,pointb);
				suma+=pointa;
				sumb+=pointb;
			}
			System.out.println("├──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┤");
			String a=String.format("Thread A earn %d Point, Thread B earn %d Point.",suma,sumb);
			String b=suma==sumb?"No body win.":suma>sumb?"Thread A win!":"Thread B win!";
			System.out.printf("│%52s%20s%4s│\n",a,b,"");
			System.out.println("└────────────────────────────────────────────────────────────────────────────┘");
		}

	}
	public static void main(String args[]) {
		Judger judger = new Judger();
		judger.start();
	}
}

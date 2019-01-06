package project9;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

public class project9 {
	static int maxnums=10;
	static int TCPport = 8000;
	static int UDPport = 8001;
	static String format(int a) {			//format int to string
		if (a==0)return "rock";
		else if (a==1)return "paper";
		else return "scissors";
	}
	static int judge(int a,int b) {		//judge score of two people
		if (a==0) {
			if (b==0) return 1;
			if (b==1) return 0;
			if (b==2) return 2;	
		}
		if (a==1) {
			if (b==0) return 2;
			if (b==1) return 1;
			if (b==2) return 0;			
		}
		if (a==2) {
			if (b==0) return 0;
			if (b==1) return 2;
			if (b==2) return 1;	
		}
		return 1;
	}

	static public class Server implements Runnable{			//server
		Object mutex=new Object();
		int nums=0;
		int pointsa=0;
		public class TCP extends Thread{	//TCP thread
			int nums=0;
			int getnum[]=new int[maxnums];
			int sleepTime[]=new int[maxnums];			@Override
			public void run() {
				try {
					ServerSocket server = new ServerSocket(TCPport);
					Socket socket = server.accept();
					DataInputStream in = new DataInputStream(socket.getInputStream());
					while (nums<maxnums) {
						sleepTime[nums]=in.readInt();
						getnum[nums]=in.readInt();
						synchronized (mutex) {
							nums++;	
						}	
					}
					server.close();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}

		public class UDP extends Thread{	//UDP thread
			int nums=0;
			int getnum[]=new int[maxnums];
			int sleepTime[]=new int[maxnums];			@Override
			public void run() {
				try {
					DatagramSocket server = new DatagramSocket(UDPport);
					while (nums!=maxnums) {
						byte[] buf = new byte[16];
						DatagramPacket receiver=new DatagramPacket(buf, 16);
						server.receive(receiver);
						getnum[nums]=buf[0]-'0';
						sleepTime[nums]=0;
						for(int i=1;buf[i]!=0;i++) {
							sleepTime[nums]*=10;
							sleepTime[nums]+=buf[i]-'0';
						}
						synchronized (mutex) {
							nums++;
						}
					}
					server.close();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
		@Override
		public void run() {
			TCP a = new TCP();
			UDP b = new UDP();
			a.start();
			b.start();
			System.out.println("┌──────────┬────────────────────────────────┬────────────────────────────────┐");
			System.out.println("│          │             Thread A           │             Thread B           │");
			System.out.println("│          ├──────────┬──────────┬──────────┼──────────┬──────────┬──────────┤");
			System.out.println("│   Round  │     Sleep│    Random│    Points│     Sleep│    Random│    Points│");
			System.out.println("│          │      time│ selection│  obtained│      time│ selection│  obtained│");
			while(nums!=maxnums) {
				synchronized (mutex) {
					if (nums<Math.min(a.nums, b.nums)) {
						System.out.println("├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤");
						System.out.printf("│%10d│%10d│%10s│%10d│%10d│%10s│%10d│\n", nums+1,a.sleepTime[nums],format(a.getnum[nums]),
								judge(a.getnum[nums], b.getnum[nums]),b.sleepTime[nums],format(b.getnum[nums]),2-judge(a.getnum[nums], b.getnum[nums]));
						pointsa+=judge(a.getnum[nums], b.getnum[nums]); 
						nums++;
					}					
				}
			}
			System.out.println("├──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┤");
			String stra=String.format("Thread A earn %d Point, Thread B earn %d Point.",pointsa,2*maxnums-pointsa);
			String strb=pointsa==2*maxnums-pointsa?"No body win.":pointsa>2*maxnums-pointsa?"Thread A win!":"Thread B win!";
			System.out.printf("│%52s%20s%4s│\n",stra,strb,"");
			System.out.println("└────────────────────────────────────────────────────────────────────────────┘");			
		}

	}
	static public class Client implements Runnable{			//client
		Random rand=new Random();
		public class TCP extends Thread{		//TCP thread
			@Override
			public void run() {
				try {
					sleep(500);
					Socket socket=new Socket("localhost",TCPport);
					DataOutputStream out=new DataOutputStream(socket.getOutputStream());
					for(int i=0;i<maxnums;i++) {
						int sleepTime;
						sleep(sleepTime=rand.nextInt(1000));
						out.writeInt(sleepTime);
						out.writeInt(rand.nextInt(3));
					}
					socket.close();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}

		public class UDP extends Thread{		//UDP thread
			@Override
			public void run() {
				try {
					sleep(500);
					DatagramSocket client = new DatagramSocket();
					for(int i=0;i<maxnums;i++) {
						int sleepTime;
						sleep(sleepTime=rand.nextInt(1000));
						byte[] data=String.format("%d%d",rand.nextInt(3),sleepTime).getBytes();
						DatagramPacket packet = new DatagramPacket(data, data.length,InetAddress.getByName("localhost"),UDPport);
						client.send(packet);
					}
					client.close();					
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}

		@Override
		public void run() {
			TCP a = new TCP();
			UDP b = new UDP();
			a.start();
			b.start();
			try {
				a.join();
				b.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	public static void main(String args[]) {
		Server server = new Server();
		Client client = new Client();
		Thread a = new Thread(server);
		Thread b = new Thread(client);
		a.start();
		b.start();
		try {
			a.join();
			b.join();		
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
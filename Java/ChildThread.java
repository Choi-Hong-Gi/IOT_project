package multi.thread.java;

public class ChildThread extends Thread {
	@Override
	public void run() {
		for (int i = 1; i <= 500; i++) {
			System.out.print("B");
			if(i % 50 ==0) 
				System.out.println();
		}
	}
}

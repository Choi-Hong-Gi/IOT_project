package multi.thread.java;

public class PrnTask implements Runnable{

	@Override
	public void run() {
		for (int i = 1; i <= 500; i++) {
			System.out.print("A");
			if(i % 50 ==0) 
				System.out.println();
		}
	}

}

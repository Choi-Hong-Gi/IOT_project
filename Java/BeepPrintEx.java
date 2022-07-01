package thread.beep.java;

import java.awt.Toolkit;

public class BeepPrintEx {

	public static void main(String[] args) {
		Thread thread = Thread.currentThread();
		

//		Toolkit toolKit = Toolkit.getDefaultToolkit();
//		Thread thread = new Thread() {@Override
//			public void run() {
//			for (int i = 0; i < 5; i++) {
//				toolKit.beep();
//				try {Thread.sleep(500);}
//				catch(Exception e) {}
//			}
//		}
//		};
//		thread.start();

		Runnable a = new BeepMaker();
		Thread b = new Thread(a);
		b.start();

		Runnable c = new BeepMaker();
		Thread d = new Thread(c);
		d.start();

		for (int i = 0; i < 5; i++) {
			System.out.println("띵");
			try {Thread.sleep(500);}
			catch(Exception e) {}
		}

		System.out.println("현 스레드 이름" + thread.getName());
	}

}

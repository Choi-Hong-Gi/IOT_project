package thread.beep.java;

import java.awt.Toolkit;

public class BeepMaker2 implements Runnable {

	Toolkit toolKit = Toolkit.getDefaultToolkit();

	@Override
	public void run() {
		for (int i = 0; i < 5; i++) {
			toolKit.beep();
			try {Thread.sleep(500);}
			catch(Exception e) {}
		}

		
	}

}

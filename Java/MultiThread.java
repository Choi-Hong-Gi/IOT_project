package multi.thread.java;

public class MultiThread {

	public static void main(String[] args) {

		
/*
���μ���: ���� ���� ���α׷�, �� ���α׷��� ���� ���μ����� ����⵵ ��
��Ƽ �½�ŷ: �� �۾� �̻� ���� ó��
(��Ƽ ���μ��� - ������ ���α׷� �������� ���� �۾�ó��,
��Ƽ ������ - �� ���α׷� ���� �� ���������� ���� �۾� ó��)

"��Ƽ ���μ��� �� ���μ��� �� ��Ƽ ������ �� ������"

������: ���α׷�, ���μ��� ������ ����Ǵ� �帧 ����
���� ������: �ڵ� ���� '�帧'
-> �ڹٴ� ���ν����尡 main() �޼ҵ� �����ϸ� ����, 
���� �����尡 �۾� ������ ���� �� ���� ����(���� ���� ���� ����)

�̱� ������ - ���� ������ ���� �� ���μ��� ����
��Ƽ ������ - ���� ���� �����尡 ������ ���μ��� ������

�۾� ������: �̸� -> �ѹ��� �ڵ� ����, thread.setName("���̸�");���� ���� ����
Thread thread = Thread.currentThread(); -> �ڵ� ���� ������ �������� ���

������ �����ٸ�: ������ ������ CPU�ھ�� ���� ���
-> ������ ���� ���ü�/���ļ� ���� �� �����ٸ�(������ ���� ���ݾ� ����)

���� �κ� �����ٸ�(Round Robin): ??
�ڹ� �켱���� �����ٸ�: �⺻ ���� 5, 1~10 ������ ����
 
*/
		
		
//		//������ ��� 1 WITH class PrnTask
//		Runnable prnTask = new PrnTask();
//		Thread thread = new Thread(prnTask);
//		thread.start();
//		
//		//������ ��� 2
//		Thread thread1 = new Thread(new Runnable() {
//
//			@Override
//			public void run() {
//				for (int i = 1; i <= 500; i++) {
//					System.out.print("C");
//					if(i % 50 ==0) 
//						System.out.println();
//				}
//			}
//		});
//		thread1.start();
		
//		//������ ��� 3 WITH class ChildThread
//		for (int i = 1; i <= 500; i++) {
//			System.out.print("B");
//			if(i % 50 ==0) 
//				System.out.println();
//		}
//		Thread thread2 = new ChildThread();
//		thread2.start();
		
//		//������ ��� 4
//		Thread thread = new Thread() {@Override
//		public void run() {
//			for (int i = 1; i <= 500; i++) {
//			System.out.print("B");
//			if(i % 50 ==0) 
//				System.out.println();
//		}}};
//		thread.start();
		
	}

}

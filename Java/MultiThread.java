package multi.thread.java;

public class MultiThread {

	public static void main(String[] args) {

		
/*
프로세스: 실행 중인 프로그램, 한 프로그램이 다중 프로세스를 만들기도 함
멀티 태스킹: 두 작업 이상 동시 처리
(멀티 프로세스 - 독립적 프로그램 실행으로 여러 작업처리,
멀티 스레드 - 한 프로그램 실행 후 내부적으로 여러 작업 처리)

"멀티 프로세스 안 프로세스 안 멀티 스레드 안 스레드"

스레드: 프로그램, 프로세스 내에서 실행되는 흐름 단위
메인 스레드: 코드 실행 '흐름'
-> 자바는 메인스레드가 main() 메소드 실행하며 시작, 
메인 스레드가 작업 스레드 생성 후 병렬 실행(사전 병렬 실행 설정)

싱글 스레드 - 메인 스레드 종류 후 프로세스 종료
멀티 스레드 - 실행 중인 스레드가 있으면 프로세스 미종료

작업 스레드: 이름 -> 넘버링 자동 설정, thread.setName("새이름");으로 지정 가능
Thread thread = Thread.currentThread(); -> 코드 실행 스레드 참조정보 얻기

스레드 스케줄링: 스레드 개수가 CPU코어보다 많을 경우
-> 스레드 순서 동시성/병렬성 결정 후 스케줄링(번갈아 가면 조금씩 실행)

라운드 로빈 스케줄링(Round Robin): ??
자바 우선순위 스케줄링: 기본 레벨 5, 1~10 변동값 가짐
 
*/
		
		
//		//스레드 방법 1 WITH class PrnTask
//		Runnable prnTask = new PrnTask();
//		Thread thread = new Thread(prnTask);
//		thread.start();
//		
//		//스레드 방법 2
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
		
//		//스레드 방법 3 WITH class ChildThread
//		for (int i = 1; i <= 500; i++) {
//			System.out.print("B");
//			if(i % 50 ==0) 
//				System.out.println();
//		}
//		Thread thread2 = new ChildThread();
//		thread2.start();
		
//		//스레드 방법 4
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

package study.exception.java;

public class ExceptionStudy {

	public static void main(String[] args) {
/*

컴파일 에러
실행 에러

에러발생 -> 프로그램 중단

예외처리: 사용자 조작 실수, 개발자 코딩 실수로 프로그램 종료를 정상 실행으로 돌림

실행 예외 종류: NullPointException, ArrayIndexOutOfBoundsException,
NumberFormatException, ClassCastException 등

try {예외 발생문;}
catch(예외클래스 e) {예외 처리문;}
finally {항상실행문;}

다중 catch:
try
catch(예외유형1 e){예외처리1;}
catch(예외유형2 e){예외처리2;}

catch(Exception e) => 최상위 예외처리 캐치
가장 마지막에 배치해야 앞에 위치한 specific한 예외처리들이 캐치됨

catch(예외유형1 | 예외유형2){예외처리;} -> 가능

throws: 메소드 선언부 끝에 작성, 메소드에서 처리하지 않은 예외를 호출한 곳으로 예외 떠넘기기
public void method1() throws ClassNotFoundException{
}
=> 발생한 예외를 호출한 메소드로 떠넘기기

사용자 정의 예외: 사용자 정의 예외 클래스 선언
-> throws 예외이름 => throw new 예외이름("출력 내용");
-> 2개의 생성자(기본 생성자, 예외메시지 출력할 String 매개변수 생성자) 정의

getMessage(): 예외발생 시 생성자 매개값으로 사용한 메세지 리턴

printStackTrace(): 예외발생 코드 추적 내용 출력


 */
		
		String data1 = "100";
		String data2 = "a100";
		
		int value1 = Integer.parseInt(data1);
		System.out.println(value1);
		try {
		int value2 = Integer.parseInt(data2);
		System.out.println(value2); // <- NumberFormatException
		}
//		catch(Exception e){
//			System.out.println("오류가 발생했습니다.");
//		}
		catch(NumberFormatException e){
			System.out.println("숫자 타입이 아닙니다.");
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("허용되는 인덱스 범위 밖입니다.");
		}
		System.out.println("계속 진행합니다.");
		
	}

}

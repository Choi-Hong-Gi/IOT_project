package study.exception.java;

public class TestException02 {
	
	int age = 32;
	String name = "홍길동";
	
	@Override
	public String toString() {
		return "나이는 " + age + "이고, 이름은 " + name ;
	}

	public static void main(String[] args) {
		TestException02 t1 = new TestException02();
		
		String dd = null;
		String dd1 = "Hellow";
//		System.out.println(dd.toString());
//		System.out.println(dd1.toString());
		
		System.out.println(dd);
		
		System.out.println(t1); // .toString() 적용
		System.out.println(t1.toString()); // String 클래스 오버라이딩
		//study.exception.java.TestException02@2d363fb3
		//객체 주소정보를 이용한 식별 값 반환(해시코드) 후 @16진수 변환
		
		int [] arr = {10, 20, 30, 40, 50};
		
		try {
			arr[6] = 70;
		}
		
		catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Keep going");
		}
		
	}

}

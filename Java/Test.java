package assinment2.java;

public class Test {
	
	public void useLibrary(Student student) {
		System.out.println(student+"이 도서관을 이용합니다.");
	}
	public void useLibrary(Staff staff) {
		System.out.println(staff +"이 도서관을 이용합니다.");
	}
	public void useLibrary(Citizen citizen) {
		System.out.println(citizen+"이 도서관을 이용합니다.");
	}
	
	public static void main(String[] args) {
		Test tt = new Test();
		Student stu01 = new Student("홍길동", "학생");
		tt.useLibrary(stu01);
		
		Staff staff01 = new Staff("임꺽정", "교직원");
		tt.useLibrary(staff01);
		
		Citizen citizen01 = new Citizen("김소원", "개신동주민");
		tt.useLibrary(citizen01);
	}
}

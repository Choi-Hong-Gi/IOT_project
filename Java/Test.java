package assinment2.java;

public class Test {
	
	public void useLibrary(Student student) {
		System.out.println(student+"�� �������� �̿��մϴ�.");
	}
	public void useLibrary(Staff staff) {
		System.out.println(staff +"�� �������� �̿��մϴ�.");
	}
	public void useLibrary(Citizen citizen) {
		System.out.println(citizen+"�� �������� �̿��մϴ�.");
	}
	
	public static void main(String[] args) {
		Test tt = new Test();
		Student stu01 = new Student("ȫ�浿", "�л�");
		tt.useLibrary(stu01);
		
		Staff staff01 = new Staff("�Ӳ���", "������");
		tt.useLibrary(staff01);
		
		Citizen citizen01 = new Citizen("��ҿ�", "���ŵ��ֹ�");
		tt.useLibrary(citizen01);
	}
}

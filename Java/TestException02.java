package study.exception.java;

public class TestException02 {
	
	int age = 32;
	String name = "ȫ�浿";
	
	@Override
	public String toString() {
		return "���̴� " + age + "�̰�, �̸��� " + name ;
	}

	public static void main(String[] args) {
		TestException02 t1 = new TestException02();
		
		String dd = null;
		String dd1 = "Hellow";
//		System.out.println(dd.toString());
//		System.out.println(dd1.toString());
		
		System.out.println(dd);
		
		System.out.println(t1); // .toString() ����
		System.out.println(t1.toString()); // String Ŭ���� �������̵�
		//study.exception.java.TestException02@2d363fb3
		//��ü �ּ������� �̿��� �ĺ� �� ��ȯ(�ؽ��ڵ�) �� @16���� ��ȯ
		
		int [] arr = {10, 20, 30, 40, 50};
		
		try {
			arr[6] = 70;
		}
		
		catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Keep going");
		}
		
	}

}

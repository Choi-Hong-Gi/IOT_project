package study.exception.java;

public class ClassException {

	public static void main(String[] args) {
		try { //forName("java.lang.String2") -> ���ܹ߻����ִ� �޼ҵ�
			Class clazz = Class.forName("java.lang.String");
		} catch (ClassNotFoundException e) {
			// �Ϲ� ����
			System.out.println("�������� �ʴ� Ŭ�����Դϴ�.");
//			e.printStackTrace();
		}
		System.out.println("�ش� Ŭ������ ��Ÿ�����͸� �����߽��ϴ�.");
		
	}

}

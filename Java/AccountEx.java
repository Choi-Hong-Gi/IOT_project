package study.exception.java;

public class AccountEx {

	public static void main(String[] args) {
		Account account = new Account();
		
		account.deposit(10000);
		System.out.println("¿¹±Ý¾×: "+ account.getBalance());
		
		try {
			account.withdraw(30000);
		}
		catch(BalanceInsufficeintException e) {
			System.out.println(e.getMessage());
		}
	}

}

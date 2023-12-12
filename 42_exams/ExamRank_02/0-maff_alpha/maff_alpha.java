public class maff_alpha {

	public static void main(String[] args) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			if (ch % 2 == 0) {
				System.out.print(Character.toUpperCase(ch));
			} else
				System.out.print(ch);
		}
		System.out.println();
	}
}

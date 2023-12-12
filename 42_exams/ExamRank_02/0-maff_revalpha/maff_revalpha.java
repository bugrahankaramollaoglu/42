public class maff_revalpha {
	public static void main(String[] args) {
		for (char ch = 'z'; ch >= 'a'; ch--) {
			if (ch % 2 == 1)
				System.out.print(Character.toUpperCase(ch));
			else
				System.out.print(ch);
		}
		System.out.println();
	}

}

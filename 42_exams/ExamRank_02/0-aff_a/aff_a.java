public class aff_a {

	/*
	 * to run: javac aff_a.java
	 * java aff_a arg1 arg2 arg3 ...
	 * C'deki char** av yerine args geçiyor
	 * C'deki int ac yerine args.length geçiyor
	 */

	public static void main(String[] args) {
		if (args.length == 2) {
			int i = 0;
			while (i < args[1].length()) {
				if (args[1].charAt(i) == 'a') {
					System.out.println("a");
					return;
				}
				i++;
			}
			System.out.println();
			return;
		}
		System.out.println("a");
	}
}

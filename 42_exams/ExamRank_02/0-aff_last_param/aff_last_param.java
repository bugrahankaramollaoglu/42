public class aff_last_param {
	public static void main(String[] args) {
		if (args.length >= 1) {
			int len = args.length;
			System.out.println(args[len - 1]);
		} else {
			System.out.println();
		}
	}
}

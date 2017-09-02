/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Bad {

    boolean isBadVersion(int version) {
        return version < 1702766719 ? false : true;
    }


    public int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            // int mid = (left + right) / 2;       // 溢出
            int mid = left + (right - left) / 2;
            boolean check = isBadVersion(mid);
            if (check == true) {
                if (mid == 1 || isBadVersion(mid-1) == false) {
                    return mid;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                left = mid + 1;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        System.out.println(new Bad().firstBadVersion(2126753390));
    }
}

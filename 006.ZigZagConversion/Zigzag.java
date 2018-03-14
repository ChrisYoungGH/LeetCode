class ZigZag {
    public String convert(String s, int numRows) {
        StringBuffer[] zigzag = new StringBuffer[numRows];
        for (int i = 0; i < zigzag.length; i++) {
            zigzag[i] = new StringBuffer();
        }

        int row = 0;
        boolean down = true;
        for (char c : s.toCharArray()) {
            zigzag[row].append(c);

            // 判断方向
            if (down == true && row + 1 == numRows) {
                down = false;
            }
            if (down == false && row - 1 < 0) {
                down = true;
            }

            // 判断是否增减行号
            if (down == true && row + 1 < numRows) {
                row++;
            }
            if (down == false && row - 1 >= 0) {
                row--;
            }
        }

        StringBuffer ans = new StringBuffer();
        for (StringBuffer sb : zigzag) {
            ans.append(sb);
        }

        return ans.toString();
    }

    public static void main(String[] args) {
        System.out.println(new ZigZag().convert("A", 1));
    }
}

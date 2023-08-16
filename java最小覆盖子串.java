public class MinWindow {

    public static String minWindow(String s, String t) {
        int m = s.length();
        int n = t.length();
        if (m < n) {
            return "";
        }

        // 构造一个哈希表，记录t中每个字符出现的次数。
        Map<Character, Integer> need = new HashMap<>();
        for (int i = 0; i < n; i++) {
            need.put(t.charAt(i), need.getOrDefault(t.charAt(i), 0) + 1);
        }

        // 构造一个滑动窗口，记录s中当前窗口中每个字符出现的次数。
        Map<Character, Integer> have = new HashMap<>();
        int left = 0;
        int right = 0;
        int minLen = m + 1;
        int minStart = -1;

        for (right = 0; right < m; right++) {
            have.put(s.charAt(right), have.getOrDefault(s.charAt(right), 0) + 1);

            // 如果窗口中包含了t中所有的字符，则开始收缩窗口。
            while (all(need.entrySet(), (e) -> have.getOrDefault(e.getKey(), 0) >= e.getValue())) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                have.put(s.charAt(left), have.getOrDefault(s.charAt(left), 0) - 1);
                left++;
            }
        }

        if (minStart == -1) {
            return "";
        } else {
            return s.substring(minStart, minStart + minLen);
        }
    }
}
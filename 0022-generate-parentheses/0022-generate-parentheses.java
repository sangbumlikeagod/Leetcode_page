class Solution {
    private void backtracking(List<String> arr, int l, int r, StringBuffer sb) {
        if (l == 0 && r == 0)
        {
            arr.add(sb.toString());
            return;
        }
        else if (r < l)
        {
            return;
        }
        if (l != 0)
        {
            sb.append('(');
            backtracking(arr, l - 1, r, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (r != 0)
        {
            sb.append(')');
            backtracking(arr, l, r - 1, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }   
    public List<String> generateParenthesis(int n) {
        List<String> answer = new ArrayList<>();
        StringBuffer sb = new StringBuffer();
        backtracking(answer, n, n, sb);
        return answer;
    }
}
class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        int n = encodedText.length();
        int columns = n / rows;

        int minNumArrays = columns - rows + 1;
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i <= minNumArrays; i++)
        {
            int ic = i;
            while (ic < n)
            {
                sb.append(encodedText.charAt(ic));
                ic += columns + 1;
            }
        }
        while (sb.isEmpty() == false && sb.charAt(sb.length() - 1) == ' ')
        {
            sb.deleteCharAt(sb.length() - 1);
        }
        return sb.toString();
    }
}
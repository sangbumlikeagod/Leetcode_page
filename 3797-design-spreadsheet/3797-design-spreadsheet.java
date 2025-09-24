class Spreadsheet {
    int[][] datas = new int[1001][26];
    // HashMap<String, Integer> 
    public Spreadsheet(int rows) {
        
    }
    public List<Integer> getCordiance(String s)
    {   
        int column = s.charAt(0) - 'A';
        int row = Integer.valueOf(s.substring(1));
        return Arrays.asList(row, column);
    }

    public void setCell(String cell, int value) {
        List<Integer> args = getCordiance(cell);
        datas[args.get(0)][args.get(1)] = value;
    }
    
    public void resetCell(String cell) {
        List<Integer> args = getCordiance(cell);
        datas[args.get(0)][args.get(1)] = 0;
        // int column = cell.charAt(0) - 'A';
        // int row = Integer.valueOf(cell.substring(1));
        // datas[row][column] = 0;
    }
    private boolean isCord(String arg){
        // System.out.println(arg);
        return 0 <= arg.charAt(0) - 'A' && arg.charAt(0) -'A' < 26;
    }
    public int getValue(String formula) {
        int sep = formula.indexOf("+");
        String A = formula.substring(1, sep);
        String B = formula.substring(sep+ 1);
        // System.out.println("A: " + A + " B: " + B);

        int a1 = 0;
        int a2 = 0;
        if (isCord(A))
        {
            List<Integer> args = getCordiance(A);
            a1 = datas[args.get(0)][args.get(1)];
        }
        else
        {
            a1 = Integer.valueOf(A);
        }
        if (isCord(B))
        {
            List<Integer> args2 = getCordiance(B);
            a2 = datas[args2.get(0)][args2.get(1)];
        }
        else
        {
            a2 = Integer.valueOf(B);
        }
        return a1 + a2;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */
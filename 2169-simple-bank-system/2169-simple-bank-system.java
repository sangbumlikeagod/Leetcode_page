class Bank {
    private long[] balance = {};
    public Bank(long[] balance) {
        this.balance = balance;
    }
    
    public boolean transfer(int account1, int account2, long money) {
        if (!withdrawable(account1, money) || !depositable(account2,money))
        {
            return false;
        }
        withdraw(account1, money);
        deposit(account2, money);
        return true;
    }
    


    public boolean deposit(int account, long money) {
        if (!depositable(account, money)) return false;
        this.balance[account - 1] += money;
        return true;
    }
    public boolean depositable(int account, long money)
    {
        return account <= this.balance.length;
    }
    
    private boolean withdrawable(int account, long money)
    {
        return account <= this.balance.length && money <= this.balance[account - 1]; 
    }
    public boolean withdraw(int account, long money) {
        if (!withdrawable(account, money)) return false;
        this.balance[account - 1] -= money;
        return true;
    }
    
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */
class Solution {
    public boolean tellCode(StringBuffer sb)
    {   

        int n = sb.length();
        if (n < 1) return false;
        for (int i = 0; i < n; i++)
        {
            char c = sb.charAt(i);
            if (!(
                c == '_' ||
                ('a' <= c && c <= 'z') ||
                ('A' <= c && c <= 'Z') ||
                ('0' <= c && c <= '9')
                )
            )
            {
                return false;
            }
        }
        return true;
    }
    public boolean tellBusinessLine(StringBuffer sb)
    {
        String s = sb.toString();
        return (
            s.compareTo("electronics") == 0 ||
            s.compareTo("grocery") == 0 ||
            s.compareTo("pharmacy") == 0 ||
            s.compareTo("restaurant") == 0  
        );
    }
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        int n = code.length;
        List<String> answerElectronics = new ArrayList<>();
        List<String> answerGrocery = new ArrayList<>();
        List<String> answerPharmacy = new ArrayList<>();
        List<String> answerRestaurant = new ArrayList<>();
        for (int i = 0; i < n; i++)
        {
            
            if (isActive[i] && tellCode(new StringBuffer(code[i])) && tellBusinessLine(new StringBuffer(businessLine[i])))
            {
                if (businessLine[i].compareTo("electronics") == 0)
                {
                    answerElectronics.add(code[i]);

                }
                else if (businessLine[i].compareTo("grocery") == 0)
                {
                    answerGrocery.add(code[i]);

                }
                else if (businessLine[i].compareTo("pharmacy") == 0)
                {
                    answerPharmacy.add(code[i]);
                    
                }
                else
                {
                    answerRestaurant.add(code[i]);
                }
            }
        }
        Collections.sort(answerElectronics);
        Collections.sort(answerGrocery);
        Collections.sort(answerPharmacy);
        Collections.sort(answerRestaurant);
        answerElectronics.addAll(answerGrocery);
        answerElectronics.addAll(answerPharmacy);
        answerElectronics.addAll(answerRestaurant);
        return answerElectronics;
    }
}
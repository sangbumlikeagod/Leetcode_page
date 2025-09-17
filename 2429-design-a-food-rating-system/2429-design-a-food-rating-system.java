class Foods implements Comparable<Foods>{
    private String food;
    private int rate;

    public Foods(String food, int rate){
        this.food = food;
        this.rate = rate;
    }
    public String getFood() {return this.food;}
    public void change_cc(int newRate){
        this.rate = newRate;
    }
    @Override
    public String toString() {
        return "Foods::" + this.food + "::" + this.rate;
    }
    @Override
    public int compareTo(Foods f)
    {
        if (this.rate != f.rate)
        {
            return this.rate - f.rate;
        }
        int stringCompare = f.food.compareTo(this.food);
        if (stringCompare != 0) {
            return stringCompare;
        }
        return f.food.length() - this.food.length();
    }
}

class FoodRatings {
    HashMap<String, TreeMap<Foods, Integer>> dataStructure = new HashMap<>();
    HashMap<String, String> foodToCuisine = new HashMap<>();
    HashMap<String, Foods> keyToFood = new HashMap<>();
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; i++)
        {

            if (dataStructure.get(cuisines[i]) == null)
            {
                dataStructure.put(cuisines[i], new TreeMap<>());   
            }
            Foods nFood = new Foods(foods[i], ratings[i]);
            dataStructure.get(cuisines[i]).put(nFood, 1);
            keyToFood.put(foods[i], nFood);
            foodToCuisine.put(foods[i], cuisines[i]);
        }
    }
    
    public void changeRating(String food, int newRating) {
        String cuisine = foodToCuisine.get(food);
        Foods foodd = keyToFood.get(food);
        dataStructure.get(cuisine).remove(foodd);
        keyToFood.get(food).change_cc(newRating);
        dataStructure.get(cuisine).put(foodd, 1);
    }
    
    public String highestRated(String cuisine) {
        return dataStructure.get(cuisine).lastKey().getFood();
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */
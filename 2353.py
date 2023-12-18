import heapq
class FoodRatings:

    def __init__(self, foods: list[str], cuisines: list[str], ratings: list[int]):
        self.cuisines =cuisines
        self.size = len(foods)
        self.ranking_sys = [[] for _ in range(self.size)] 
        self.version = [0] * self.size
        self.menu = {}
        self.category = {}
        
        for i in range(self.size):
            self.menu[foods[i]] = i
            if cuisines[i] not in self.category:
                self.category[cuisines[i]] = i
            heapq.heappush(self.ranking_sys[self.category[cuisines[i]]], (-ratings[i], foods[i] ,self.version[i]))  


    def changeRating(self, food: str, newRating: int) -> None:
        self.version[self.menu[food]] += 1
        heapq.heappush(self.ranking_sys[self.category[self.cuisines[self.menu[food]]]], (-newRating, food ,self.version[self.menu[food]]))

    def highestRated(self, cuisine: str) -> str:
        while self.ranking_sys[self.category[cuisine]]:
            if self.ranking_sys[self.category[cuisine]][0][2] != self.version[self.ranking_sys[self.category[cuisine]][0][1]]: 
                heapq.heappop(self.ranking_sys[self.category[cuisine]])
            else:
                return self.ranking_sys[self.category[cuisine]][0][1]
                
        
        


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
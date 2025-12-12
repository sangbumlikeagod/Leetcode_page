class Solution:

    def __init__(self):
        self.q = []
        self.is_online = []
        self.alls = 0
        
    def process_queue(self, time):
        # print(self.q)
        while (self.q and self.q[0][0] <= time):
            _, id = heapq.heappop(self.q)
            self.is_online[id] = 1
        
            
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        self.is_online = [1] * numberOfUsers
        answer = [0] * numberOfUsers
        
        events = sorted(events, key= lambda x : int(x[1]) if x[0] == 'OFFLINE' else int(x[1]) + 0.1)
        # print(events)
        
        def process_online(ids : str):
            if ids == "HERE":
                for i in range(numberOfUsers):
                    answer[i] += self.is_online[i]
            elif ids == "ALL":
                self.alls  += 1
            else:
                # print(ids)
                names = map(lambda x: int(x[2:]), ids.split())
                for name in names:
                    answer[name] += 1
                
                        
            ...
        for event in events:

            self.process_queue(int(event[1]))
            if event[0] == "MESSAGE":
                process_online(event[2])
                #
            else:
                heapq.heappush(self.q, [int(event[1]) + 60, int(event[2])])
                self.is_online[int(event[2])] = 0

        for i in range(numberOfUsers):
            answer[i] += self.alls 
        return answer
                
                
class Multi_set:
    def __init__(self):
        self.items = []

    def add(self, number):
        return self.items.append(number)

    def removeAll(self, number):
        while (self.items.count(number) > 0):
            self.items.remove(number)
        return self.items

    def remove(self, number):
        if self.items.count(number) != 0:
            return self.items.remove(number)

    def multiplicity(self, number):
        counter_b = self.items.count(number)
        return(counter_b)

    def union(self, newset):
        answer = self.items + newset.items
        templist = list(dict.fromkeys(answer))

        for i in templist:
            if((self.multiplicity(i)) > (newset.multiplicity(i))):
                for k in range((newset.multiplicity(i)), 0, -1):
                    answer.remove(i)
            else:
                if((self.multiplicity(i)) < (newset.multiplicity(i))):
                    for v in range((self.multiplicity(i)), 0, -1):
                        answer.remove(i)

        return answer

    def contains(self, number):
        return number in self.items

    def intersection(self, newset):
        answer = Multi_set()
        templist = list(dict.fromkeys(self.items+newset.items))

        for i in templist:
            if(self.contains(i) and newset.contains(i)):
                if(self.multiplicity(i) < newset.multiplicity(i)):
                    for k in range(0, self.multiplicity(i), 1):
                        answer.add(i)
                else:
                    if(self.multiplicity(i) > newset.multiplicity(i)):
                        for v in range(0, newset.multiplicity(i), 1):
                            answer.add(i)
                    else:
                        if(self.multiplicity(i) == newset.multiplicity(i)):
                            for v in range(0, newset.multiplicity(i), 1):
                                answer.add(i)

        return answer.items

    def difference(self, newset):
        templist = list(dict.fromkeys(newset.items))
        for i in templist:
            if(self.contains(i) and newset.contains(i)):
                for k in range(0, newset.multiplicity(i), 1):
                    self.remove(i)

        return self.items

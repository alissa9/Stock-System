CXX = g++
CXXFLAGS = -g -Wall -Wextra 

.PHONEY= all 

stock: stock.cpp
	$(CXX) $(CXXFLAGS) -o $@ stock.cpp 
	
	

.PHONEY : clean
clean:
	rm -rf *o stock






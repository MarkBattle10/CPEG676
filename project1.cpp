//Project1 creating the twitter tweeter
//first step is to parse data and place it in an array (of size 280 chars)
//second step is to use the markovian chain algorithm on the array
//markov property only depends on where i am now and not the past.
//treat every word as a state and predict the next word based on the previous state
//when a word is added, have to add one to total for that pair and add 
//one to the word appearing next based on the prev state and then divide by the 
//total to get the percentage that that word will be next
//third step is to spit out your own tweet no greater than 280 characters
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

//typedef pair<string,string> strPair;

//void calcProbability();

int main(){
	//typedef vector<string> vecString;
	
	multimap<pair<string,string>, pair<string,double> markovMMap;
	//multimap<strPair, string> markovMMap;
	int i=0;
	//vector<string> tweetVect;
	string tweetArr[280];
	ifstream file;
	ofstream outFile;
	file.open("tweet.txt");

	while(file){
		file >> tweetArr[i];
		if(i>1){
			markovMMap.insert(make_pair(make_pair(tweetArr[i-2],tweetArr[i-1]),make_pair(tweetArr[i],0)));

		}
		else if(i=1){
			markovMMap.insert(make_pair(make_pair("empty",tweetArr[i-1]),make_pair(tweetArr[i],0)));
		
		}
		else{
			markovMMap.insert(make_pair(make_pair("empty","empty"),make_pair(tweetArr[i],0)));
	
		}
		i++;
	}

	multimap<pair<string,string>,pair<string,double>>::iterator iter1;
	multimap<pair<string,string>,pair<string,double>>::iterator iter2;
	
	int countArr[markovMMap.size()];
	int index = 0;
	int totalCount;
	for(iter1 = markovMMap.begin(); iter1 != markovMMap.end(); ++iter1){
		totalCount = 0;
		for(iter2 = markovMMap.begin(); iter2 != markovMMap.end(); ++iter2){
			if(iter2 != iter1){
				if((iter2->first.first == iter1->first.first) && (iter2->first.second == iter1->first.second)){
					totalCount = totalCount+1;
				}
				iter2->second.second = iter2->second.second + 1;
			}
			
		}
		countArr[index] = totalCount;
		index = index+1
	}
	
	index = 0;
	for(iter1 = markovMMap.begin(); iter1 != markovMMap.end(); ++iter1){
		if(iter1->second.second != 0){
			iter1->second.second = (iter1->second.second)/(countArr[index]);	
		}
		index = index+1;
	}
	
	
	
	outFile.open("tweetOut.txt");	
	
	multimap<pair<string,string>,pair<string,double>>::iterator iter;

	for(iter = markovMMap.begin(); iter != markovMMap.end(); ++iter){
		outFile << iter->first.first << " " << iter->first.second << " " << iter->second.first << " " << iter->second.second << endl;
	}

	return 0;

}

/*

void calcProbability(struct Word *word, struct State *wordState){
	word->probability = word->thisWord/word->totalWords;
}
*/

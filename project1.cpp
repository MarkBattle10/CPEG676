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
	
	multimap<pair<string,string>, string> markovMMap;
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
			markovMMap.insert(make_pair(make_pair(tweetArr[i-2],tweetArr[i-1]),tweetArr[i]));

		}
		else if(i=1){
			markovMMap.insert(make_pair(make_pair("empty",tweetArr[i-1]),tweetArr[i]));
		
		}
		else{
			markovMMap.insert(make_pair(make_pair("empty","empty"),tweetArr[i]));
	
		}
		i++;
	}

	outFile.open("tweetOut.txt");

	multimap<pair<string,string>,string>::iterator iter;

	for(iter = markovMMap.begin(); iter != markovMMap.end(); ++iter){
		outFile << iter->first.first << " " << iter->first.second << " " << iter->second << endl;
	}

	return 0;

}

/*

void calcProbability(struct Word *word, struct State *wordState){
	word->probability = word->thisWord/word->totalWords;
}
*/

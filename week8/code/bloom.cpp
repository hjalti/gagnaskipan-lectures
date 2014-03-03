#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Hash
{
    public:
        Hash(int seed);
        unsigned int hash(string s);

    private:
        int seed;
};

Hash::Hash(int seed)
{
    this->seed = seed;
}

// MurmurHash2
unsigned int Hash::hash(string s)
{
    int len = static_cast<int>(s.size());

	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.
	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	// Initialize the hash to a 'random' value
	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash
	const unsigned char * data = (const unsigned char *)s.c_str();

	while(len >= 4) {
		unsigned int k = *(unsigned int *)data;

		k *= m;
		k ^= k >> r;
		k *= m;

		h *= m;
		h ^= k;

		data += 4;
		len -= 4;
	}

	// Handle the last few bytes of the input array

	switch(len) {
        case 3:
            h ^= data[2] << 16;
        case 2:
            h ^= data[1] << 8;
        case 1:
            h ^= data[0];
            h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
}

typedef Hash* HashPtr;

class HashCollection
{
    public:
        HashCollection(int size);
        ~HashCollection();

        int size();
        unsigned int get_hash(int n, string s);

    private:
        int count;
        HashPtr *list;
};

HashCollection::HashCollection(int size)
{
    count = size;
    list = new HashPtr[size];

    for(int i = 0; i < size; i++) {
        list[i] = new Hash(rand());
    }
}

unsigned int HashCollection::get_hash(int n, string s)
{
    return list[n]->hash(s);
}

HashCollection::~HashCollection()
{
    for(int i = 0; i < count; i++) {
        delete list[i];
    }

    delete [] list;
}

int HashCollection::size()
{
    return count;
}


int main()
{
    srand(time(NULL));
    HashCollection hc(100);
    for(int i = 0; i < hc.size(); i++) {
        cout << hc.get_hash(i, "hulda") % 30000 << endl;
    }

    return 0;
}

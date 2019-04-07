#include <cstdio>
#include <vector>

using namespace std;

struct segment{
    int st, ed;   // index of input bits
    int sti, edi; // index of output bits
};

int N, B, F;
vector<segment> vec, tvec;
char ss[1050];

int main()
{
    int T;
    scanf("%d", &T);
    setbuf(stdout, NULL);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d %d %d", &N, &B, &F);

        vec.clear();
        // Phase 1
        for(int i=0;i<(N+15)/16;i++)
        {
            for(int j=0;j<16;j++)
                ss[i*16 + j] = "10"[i%2];
        }
        ss[N] = 0;
        printf("%s\n", ss);
        
        scanf("%s", ss);
        int idx, sti, edi;
        idx = sti = edi = 0;
        for(int i=0;i<(N+15)/16;i++)
        {
            sti = edi;
            while(ss[edi]=="10"[i%2]) edi++;
            vec.push_back({i*16, min(i*16+15, N-1), sti, edi-1});
        }

        // Phase 2
        for(int q=2;q<=F;q++)
        {
            for(auto sg : vec)
            {
                int mid = (sg.st + sg.ed)/2;
                for(int i=sg.st;i<=mid;i++)
                    ss[i] = '1';
                for(int i=mid+1;i<=sg.ed;i++)
                    ss[i] = '0';
            }
            printf("%s\n", ss);
            scanf("%s", ss);

            tvec.clear();
            for(auto sg : vec)
            {
                int mid = (sg.st + sg.ed)/2;
                int mi;

                for(mi = sg.sti; ss[mi]=='1' && mi<=sg.edi; mi++);

                if(sg.st <= mid)
                    tvec.push_back({sg.st, mid, sg.sti, mi-1});
                if(mid+1 <= sg.ed)
                    tvec.push_back({mid+1, sg.ed, mi, sg.edi});
            }
            vec = tvec;
        }

        // Answer
        for(auto sg : vec)
        {
            if(sg.sti > sg.edi)
                printf("%d ", sg.st);
        }
        printf("\n");
        scanf("%d", &N);
    }

    return 0;
}
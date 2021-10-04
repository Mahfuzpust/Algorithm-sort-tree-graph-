    //kruskal algorithm
    #include<stdio.h>
    #include<conio.h>
    #include<stdlib.h>
    int i,j,k,a,b,u,v,n,ne=1;
    int min,mincost=0,cost[9][9],parent[9];
    int find(int i);// parent khujar jonno use kora hoi
    int uni(int i,int j);// parent select korar jonno use kora hoi
    void main()
    {

        printf("\n\tImplementation of Kruskal's algorithm\n");
        printf("\nEnter the no. of vertices:");
        scanf("%d",&n);
        printf("\nEnter the cost adjacency matrix:\n");
        //nodes 1 to n
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&cost[i][j]);
                if(cost[i][j]==0)
                cost[i][j]=999;
            }
        }
        printf("The edges of Minimum Cost Spanning Tree are\n");
        while(ne < n)  //for all nodes
        {
            for(i=1,min=999;i<=n;i++)
            {
                for(j=1;j <= n;j++)
                {
                    if(cost[i][j] < min)// vertex er moddhe connect ache kina
                    {
                        min=cost[i][j];// min er value ber hobe
                        a=u=i;
                        b=v=j;// next vertex e jabe
                    }
                }
            }
            //
            u=find(u);  //the node in constructing tree from which u has an edge. if no such node u itself.
            v=find(v); //the node in constructing tree from which v has an edge. if no such node v itself.
            if(uni(u,v))  //checks if u and v are same nodes or different. if different make one node parent to other
            {
                printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
                mincost +=min;
            }
            cost[a][b]=cost[b][a]=999;  //after taking the edge into spanning tree cost incresese to infinity so thet it can not be next candidte edge
        }
        printf("\n\tMinimum cost = %d\n",mincost);

    }
    int find(int i)
    {
        while(parent[i])  //checks whether any node of constructing tree has an edge with i. If such a node found that node is parent of i
        {
            i=parent[i];
        }

        return i;
    }
    int uni(int i,int j)  //makes a node parent to another if there is an edge between i and j
    {
        if(i!=j)
        {
            parent[j]=i;
            return 1;
        }
        return 0;
    }

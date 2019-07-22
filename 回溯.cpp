//
// Created by 1655664358@qq.com on 2019/7/22.
//

void powerSet(int i,int n){
    if(i>n){
        for(int j=1;j<=n;j++){
            if (set[j]==1){
                printf("%d",j);
            }

        }
        printf("\n");
    }else{
        set[1]=1;{
            void powerSet(int 2,int n){
                if(i>n){
                    for(int j=1;j<=n;j++){
                        if (set[j]==1){
                            printf("%d",j);
                        }

                    }
                    printf("\n");
                }else{
                    set[2]=1;{
                        void powerSet(int 3,int n){
                            if(i>n){
                                for(int j=1;j<=n;j++){
                                    if (set[j]==1){
                                        printf("%d",j);
                                    }

                                }
                                printf("\n");
                            }else{
                                set[3]=1;{
                                    void powerSet(int 4,int n){
                                        if(i>n){
                                            for(int j=1;j<=n;j++){
                                                if (set[j]==1){
                                                    printf("%d",j);//123
                                                }

                                            }
                                            printf("\n");
                                        }else{
                                            set[i]=1;powerSet(i+1,n);

                                            set[i]=0;powerSet(i+1,n);
                                        }
                                    }
                                };
                                //set[3]=0
                                set[i]=0;{
                                    void powerSet(int 4,int n){
                                        if(i>n){
                                            for(int j=1;j<=n;j++){
                                                if (set[j]==1){
                                                    printf("%d",j);//12
                                                }

                                            }
                                            printf("\n");
                                        }else{
                                            set[i]=1;powerSet(i+1,n);

                                            set[i]=0;powerSet(i+1,n);
                                        }
                                    }
                                };
                            }
                        }
                    };
                    //set[2]=0
                    set[i]=0;{
                        void powerSet(int 3,int n){
                            if(i>n){
                                for(int j=1;j<=n;j++){
                                    if (set[j]==1){
                                        printf("%d",j);
                                    }

                                }
                                printf("\n");
                            }else{
                                //set[3]=1
                                set[i]=1;{
                                    void powerSet(int i,int n){
                                        if(i>n){
                                            for(int j=1;j<=n;j++){
                                                if (set[j]==1){
                                                    printf("%d",j);//13
                                                }

                                            }
                                            printf("\n");
                                        }else{
                                            set[i]=1;powerSet(i+1,n);

                                            set[i]=0;powerSet(i+1,n);
                                        }
                                    }
                                };
                                //set[3]=0 set[2]=0
                                set[i]=0;{
                                    void powerSet(int i,int n){
                                        if(i>n){
                                            for(int j=1;j<=n;j++){
                                                if (set[j]==1){
                                                    printf("%d",j);//1
                                                }

                                            }
                                            printf("\n");
                                        }else{
                                            set[i]=1;powerSet(i+1,n);

                                            set[i]=0;powerSet(i+1,n);
                                        }
                                    }

                                };
                            }
                        }
                    };
                }
            }
        };
        //set[1]=0
        set[i]=0;{
            void powerSet(int 2,int n){
                if(i>n){
                    for(int j=1;j<=n;j++){
                        if (set[j]==1){
                            printf("%d",j);
                        }

                    }
                    printf("\n");
                }else{
                    //set[2]=1
                    set[i]=1;{
                        void powerSet(int 3,int n){
                            if(i>n){
                                for(int j=1;j<=n;j++){
                                    if (set[j]==1){
                                        printf("%d",j);
                                    }

                                }
                                printf("\n");
                            }else{
                                //set[3]=1
                                set[i]=1;{
                                    void powerSet(int i,int n){
                                        if(i>n){
                                            for(int j=1;j<=n;j++){
                                                if (set[j]==1){
                                                    printf("%d",j);//23
                                                }

                                            }
                                            printf("\n");
                                        }else{
                                            set[i]=1;powerSet(i+1,n);

                                            set[i]=0;powerSet(i+1,n);
                                        }
                                    }
                                };
                                //set[1]=0 set[3]=0
                                set[i]=0;{
                                    void powerSet(int i,int n){
                                        if(i>n){
                                            for(int j=1;j<=n;j++){
                                                if (set[j]==1){
                                                    printf("%d",j);//2
                                                }

                                            }
                                            printf("\n");
                                        }else{
                                            set[i]=1;powerSet(i+1,n);

                                            set[i]=0;powerSet(i+1,n);
                                        }
                                    }
                                };
                            }
                        }
                    };
                    //set[2]=0
                    set[i]=0;{
                        void powerSet(int 3,int n){
                            if(i>n){
                                for(int j=1;j<=n;j++){
                                    if (set[j]==1){
                                        printf("%d",j);
                                    }

                                }
                                printf("\n");
                            }else{
                                //set[3]=1
                                set[i]=1;{
                                    void powerSet(int i,int n){
                                        if(i>n){
                                            for(int j=1;j<=n;j++){
                                                if (set[j]==1){
                                                    printf("%d",j);//3
                                                }

                                            }
                                            printf("\n");
                                        }else{
                                            set[i]=1;powerSet(i+1,n);

                                            set[i]=0;powerSet(i+1,n);
                                        }
                                    }
                                }});

                                set[i]=0;powerSet(i+1,n);
                            }
                        }
                    };
                }
            }
        };
    }
}
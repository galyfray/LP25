
char* strcut(char *cutStr,char *strToCut,int From,int To)/* tronque la chaine de caract�re de From � To */
{
    int i;
    for(i=From;i<To;i++)
    {
        cutStr[i-From]=strToCut[i];
    }
    cutStr[To-From]='\0';
    return cutStr;
}

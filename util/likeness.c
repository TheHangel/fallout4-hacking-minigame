#define STRLEN 4

int likeness( const char *password, const char *wordchosen ) 
{
    if ( strlen( password ) != STRLEN || strlen( wordchosen ) != STRLEN ) 
    {
        return -1;
    }

    if ( strcmp( password, wordchosen ) == 0 ) 
    {
        return STRLEN;
    }

    int like = 0;

    for ( const char *p = password; *p; ++p )
    {
        if ( memchr( password, *p, p - password ) == NULL && 
             strchr( wordchosen, *p ) != NULL )
        {
            ++like;
        }            
    }

    return like;
}
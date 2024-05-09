#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSetv(int count, ...)
{
    IntSortedSetADT set = mkSSet();
    // printf("Count: %d\n", count);

    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        int num = va_arg(args, int);
        // printf("i: %d\n", i);
        sset_add(set, num);
    }
    va_end(args);
    return set;
}

char *toString(IntSortedSetADT set)
{
    char *sout = malloc(100 * sizeof(char));

    ListNodePtr nptr = set->first;
    while (nptr)
    {
        if (nptr == set->first)
            sprintf(sout + strlen(sout), "%d", nptr->elem);
        else
            sprintf(sout + strlen(sout), ",%d", nptr->elem);
        nptr = nptr->next;
    }

    sprintf(sout + strlen(sout), "}");

    return sout;
}

int check_mkSSet()
{
    int passed = 1;
    printf("mkSet()\n");
    IntSortedSetADT sptr = mkSSet();
    if (!sptr)
    {
        printf("FAILED");
        printf("EXPECTED: not %d\n", 0);
    }
    else
        printf("OK\n");
    printf("RESULT:%ld\n\n", (long)sptr);
    return passed;
}

int check_dsSSet()
{
    int passed = 1;

    if (passed)
    {
        _Bool rv;
        IntSortedSetADT sptr = mkSSet();
        printf("dsSSet({})\n");
        rv = dsSSet(&sptr);
        if (!rv || sptr)
        {
            printf("FAILED\n");
            printf("EXPECTED: NOT %d AND PTR %ld\n", 0, (long)NULL);
            passed = 0;
        }
        else
        {
            printf("OK\n");
        }
        printf("RESULT:%d AND PTR %ld\n\n", rv, (long)sptr);
    }

    if (passed)
    {
        _Bool rv;
        printf("dsSSet(NULL)\n");
        rv = dsSSet(NULL);
        if (rv)
        {
            printf("FAILED\n");
            printf("EXPECTED: %d\n", 0);
            passed = 0;
        }
        else
        {
            printf("OK\n");
        }
        printf("RESULT:%d\n\n", rv);
    }

    return passed;
}

int check_sset_add()
{
    int passed = 1;
    _Bool rv;
    printf("sset_add(NULL,5)\n");
    rv = sset_add(NULL, 5);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);

    return passed;
}

int check_sset_add2()
{
    int passed = 1;
    _Bool rv;
    IntSortedSetADT sptr = mkSSet();
    printf("sset_add({},5)\n");
    rv = sset_add(sptr, 5);
    if (!rv || sptr->size != 1)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d WITH SIZE %d\n", 0, 1);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d WITH SIZE %d\n", rv, sptr->size);
    dsSSet(&sptr);

    return passed;
}

int check_sset_add3()
{
    int passed = 1;
    _Bool rv;
    IntSortedSetADT sptr = mkSSet();
    sset_add(sptr, 3);
    sset_add(sptr, 5);
    printf("sset_add({3, 5},5)\n");
    rv = sset_add(sptr, 5);
    if (rv || sptr->size != 2)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d WITH SIZE %d\n", 0, 1);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d WITH SIZE %d\n", rv, sptr->size);
    dsSSet(&sptr);

    return passed;
}

int check_sset_remove()
{
    int passed = 1;
    _Bool rv;

    printf("sset_remove(NULL,3)\n");
    rv = sset_remove(NULL, 3);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);
    return passed;
}

int check_sset_remove2()
{
    int passed = 1;
    _Bool rv;

    printf("sset_remove({},3)\n");
    IntSortedSetADT sptr = mkSSet();
    rv = sset_remove(sptr, 3);
    if (rv || sptr->size != 0)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d WITH SIZE %d\n", 0, 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d WITH SIZE %d\n", rv, sptr->size);
    dsSSet(&sptr);

    return passed;
}

int check_sset_remove3()
{
    int passed = 1;
    _Bool rv;

    printf("sset_remove({5,7},3)\n");
    IntSortedSetADT sptr = mkSSetv(2, 5, 7);
    rv = sset_remove(sptr, 3);
    if (rv || sptr->size != 2)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d WITH SIZE %d\n", 0, 2);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d WITH SIZE %d\n", rv, sptr->size);
    dsSSet(&sptr);

    return passed;
}

int check_sset_remove4()
{
    int passed = 1;
    _Bool rv;

    printf("sset_remove({5,7},5)\n");
    IntSortedSetADT sptr = mkSSetv(2, 5, 7);
    rv = sset_remove(sptr, 5);
    if (!rv || sptr->size != 1)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d WITH SIZE %d\n", 0, 1);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d WITH SIZE %d\n", rv, sptr->size);
    dsSSet(&sptr);

    return passed;
}

int check_sset_remove5()
{
    int passed = 1;
    _Bool rv;

    printf("sset_remove({7},7)\n");
    IntSortedSetADT sptr = mkSSetv(1, 7);
    rv = sset_remove(sptr, 7);
    if (!rv || sptr->size != 0)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d WITH SIZE %d\n", 0, 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d WITH SIZE %d\n", rv, sptr->size);
    dsSSet(&sptr);

    return passed;
}

int check_sset_member()
{
    int passed = 1;
    _Bool rv;

    printf("sset_member(NULL,3)\n");
    rv = sset_member(NULL, 3);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);

    return passed;
}

int check_sset_member2()
{
    int passed = 1;
    _Bool rv;

    printf("sset_member({5,7},3)\n");
    IntSortedSetADT sptr = mkSSetv(2, 5, 7);
    rv = sset_member(sptr, 3);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_sset_member3()
{
    int passed = 1;
    _Bool rv;

    printf("sset_member({5,7},5)\n");
    IntSortedSetADT sptr = mkSSetv(2, 5, 7);
    rv = sset_member(sptr, 5);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = false;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_sset_member4()
{
    int passed = 1;
    _Bool rv;

    printf("sset_member({5,7},7)\n");
    IntSortedSetADT sptr = mkSSetv(2, 5, 7);
    rv = sset_member(sptr, 7);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_isEmptySet()
{
    int passed = 1;
    _Bool rv;

    printf("isEmptySet(NULL)\n");
    rv = isEmptySSet(NULL);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);

    return passed;
}

int check_isEmptySet2()
{
    int passed = 1;
    _Bool rv;

    printf("isEmptySSet({})\n");
    IntSortedSetADT sptr = mkSSet();
    rv = isEmptySSet(sptr);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_isEmptySet3()
{
    int passed = 1;
    _Bool rv;

    printf("isEmptySSet({5})\n");
    IntSortedSetADT sptr = mkSSetv(1, 5);
    rv = isEmptySSet(sptr);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_set_size1()
{
    int passed = 1;
    int rv;

    printf("sset_size(NULL)\n");
    rv = sset_size(NULL);
    if (rv != -1)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", -1);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);

    return passed;
}

int check_set_size2()
{
    int passed = 1;
    int rv;

    printf("sset_size({})\n");
    IntSortedSetADT sptr = mkSSet();
    rv = sset_size(sptr);
    if (rv != 0)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_set_size3()
{
    int passed = 1;
    int rv;

    printf("sset_size({5})\n");
    IntSortedSetADT sptr = mkSSetv(1, 5);
    rv = sset_size(sptr);
    if (rv != 1)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 1);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_set_size4()
{
    int passed = 1;
    int rv;

    printf("sset_size({5,7})\n");
    IntSortedSetADT sptr = mkSSetv(2, 5, 7);
    rv = sset_size(sptr);
    if (rv != 2)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 2);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_set_extract1()
{
    int passed = 1;
    _Bool rv;
    int dat;

    printf("sset_extract(NULL)\n");
    rv = sset_extract(NULL, &dat);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);

    return passed;
}

int check_set_extract2()
{
    int passed = 1;
    _Bool rv;
    int dat;

    printf("sset_extract({})\n");
    IntSortedSetADT sptr = mkSSet();
    rv = sset_extract(sptr, &dat);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);
    dsSSet(&sptr);

    return passed;
}

int check_set_extract3()
{
    int passed = 1;
    _Bool rv;
    int dat1, dat2, dat3;

    IntSortedSetADT sptr = mkSSetv(3, 3, 5, 7);
    printf("sset_extract(%s)\n", toString(sptr));
    rv = sset_extract(sptr, &dat1);
    if (!rv || (dat1 != 3 && dat1 != 5 && dat1 != 7))
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d AND VALUE IN %s\n", 0, toString(sptr));
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d AND VALUE %d\n", rv, dat1);

    if (passed)
    {
        printf("sset_extract(%s))\n", toString(sptr));
        rv = sset_extract(sptr, &dat2);
        if (!rv || dat2 == dat1 || (dat2 != 3 && dat2 != 5 && dat2 != 7))
        {
            printf("FAILED\n");
            printf("EXPECTED: NOT %d AND VALUE IN %s\n", 0, toString(sptr));
            passed = 0;
        }
        else
        {
            printf("OK\n");
        }
        printf("RESULT:%d AND VALUE %d\n", rv, dat2);
    }

    if (passed)
    {
        printf("sset_extract(%s)\n", toString(sptr));
        rv = sset_extract(sptr, &dat3);
        if (!rv || dat3 == dat1 || dat3 == dat2 || (dat3 != 3 && dat3 != 5 && dat3 != 7))
        {
            printf("FAILED\n");
            printf("EXPECTED: NOT %d  AND VALUE IN %s\n", 0, toString(sptr));
            passed = 0;
        }
        else
        {
            printf("OK\n");
        }
        printf("RESULT:%d AND VALUE %d\n", rv, dat3);
    }
    dsSSet(&sptr);

    return passed;
}

int check_set_equals1()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    printf("sset_equals(NULL, {})\n");
    rv = sset_equals(NULL, sptr1);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);
    dsSSet(&sptr1);

    return passed;
}

int check_set_equals2()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    printf("sset_equals({}, NULL)\n");
    rv = sset_equals(sptr1, NULL);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);
    dsSSet(&sptr1);

    return passed;
}

int check_set_equals3()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT sptr2 = mkSSet();
    printf("set_equals({}, {})\n");
    rv = sset_equals(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_equals4()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT sptr2 = mkSSetv(3, 3, 5, 7);
    printf("sset_equals({}, {3,5,7})\n");
    rv = sset_equals(sptr2, sptr1);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_equals5()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSetv(3, 3, 5, 7);
    printf("sset_equals({3,5,7}, {3,5,7})\n");
    rv = sset_equals(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_equals6()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSetv(3, 7, 5, 3);
    printf("sset_equals({3,5,7}, {7,5,3})\n");
    rv = sset_equals(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: true\n");
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subseteq1()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    printf("sset_subseteq(NULL, {})\n");
    rv = sset_subseteq(NULL, sptr1);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);
    dsSSet(&sptr1);

    return passed;
}

int check_subseteq2()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    printf("sset_subseteq({}, NULL)\n");
    rv = sset_subseteq(sptr1, NULL);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);
    dsSSet(&sptr1);

    return passed;
}

int check_subseteq3()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSet();
    printf("sset_subseteq({}, {3,5,7})\n");
    rv = sset_subseteq(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subseteq4()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSetv(1, 3);
    printf("sset_subseteq({3}, {3,5,7})\n");
    rv = sset_subseteq(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subseteq5()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSet(2, 3, 5);
    printf("sset_subseteq({3,5}, {3,5,7})\n");
    rv = sset_subseteq(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subseteq6()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSet(3, 3, 5, 7);
    printf("sset_subseteq({3,5,7}, {3,5,7})\n");
    rv = sset_subseteq(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subseteq7()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSetv(4, 3, 5, 7, 9);
    printf("sset_subseteq({3,5,7,9}, {3,5,7})\n");
    rv = sset_subseteq(sptr2, sptr1);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subseteq8()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT sptr2 = mkSSetv(1, 5);
    printf("sset_subseteq({5}, {})\n");
    rv = sset_subseteq(sptr2, sptr1);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subset1()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    printf("subset(NULL, {})\n");
    rv = sset_subset(NULL, sptr1);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);
    dsSSet(&sptr1);

    return passed;
}

int check_subset2()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSet();
    printf("subset({}, NULL)\n");
    rv = sset_subset(sptr1, NULL);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %d\n", rv);
    dsSSet(&sptr1);

    return passed;
}

int check_subset3()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSet();
    printf("subset({}, {3,5,7})\n");
    rv = sset_subset(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subset4()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSetv(1, 3);
    printf("subset({3}, {3,5,7})\n");
    rv = sset_subset(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subset5()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSet(2, 3, 5);
    printf("subset({3,5}, {3,5,7})\n");
    rv = sset_subset(sptr2, sptr1);
    if (!rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_subset6()
{
    int passed = 1;
    _Bool rv;

    IntSortedSetADT sptr1 = mkSSetv(3, 3, 5, 7);
    IntSortedSetADT sptr2 = mkSSetv(3, 3, 5, 7);
    printf("subset({3,5,7}, {3,5,7})\n");
    rv = sset_subset(sptr2, sptr1);
    if (rv)
    {
        printf("FAILED\n");
        printf("EXPECTED: %d\n", 0);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT:%d\n", rv);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_union1()
{
    int passed = 1;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT uset;
    printf("set_union({},NULL)\n");
    uset = sset_union(sptr1, NULL);
    if (uset)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %ld\n", (long)uset);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }

    return passed;
}

int check_set_union2()
{
    int passed = 1;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT uset;
    printf("set_union(NULL,{})\n");
    uset = sset_union(NULL, sptr1);
    if (uset)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %ld\n", (long)uset);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }

    return passed;
}

int check_set_union3()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT uset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSet();
    printf("set_union({3,5,7},{})\n");
    uset = sset_union(sptr1, sptr2);
    expset = mkSSetv(3, 7, 5, 3);
    if (!sset_equals(uset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", "{7,5,3}");
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(uset));
    dsSSet(&expset);
    dsSSet(&uset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_union4()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT uset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSetv(1, 5);
    uset = sset_union(sptr1, sptr2);
    printf("set_union({3,5,7},{5})\n");
    expset = mkSSetv(3, 7, 5, 3);
    if (!sset_equals(uset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", "{7,5,3}");
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(uset));
    dsSSet(&expset);
    dsSSet(&uset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_union5()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT uset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSetv(1, 9);
    uset = sset_union(sptr1, sptr2);
    printf("set_union({3,5,7},{9})\n");
    expset = mkSSetv(4, 9, 7, 5, 3);
    if (!sset_equals(uset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", "{9,7,5,3}");
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(uset));
    dsSSet(&expset);
    dsSSet(&uset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_intersection1()
{
    int passed = 1;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT uset;
    printf("set_intersection({},NULL)\n");
    uset = sset_intersection(sptr1, NULL);
    if (uset)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %ld\n", (long)uset);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }

    return passed;
}

int check_set_intersection2()
{
    int passed = 1;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT uset;
    printf("set_intersection(NULL,{})\n");
    uset = sset_intersection(NULL, sptr1);
    if (uset)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %ld\n", (long)uset);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }

    return passed;
}

int check_set_intersection3()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT iset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSet();
    iset = sset_intersection(sptr1, sptr2);
    printf("set_intersection({3,5,7},{})\n");
    expset = mkSSet();
    if (!sset_equals(iset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", toString(expset));
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(iset));
    dsSSet(&expset);
    dsSSet(&iset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_intersection4()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT iset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSetv(1, 5);
    iset = sset_intersection(sptr1, sptr2);
    printf("set_intersection({3,5,7},{5})\n");
    expset = mkSSetv(1, 5);
    if (!sset_equals(iset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", toString(expset));
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(iset));
    dsSSet(&expset);
    dsSSet(&iset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_intersection5()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT iset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSetv(3, 5, 7, 9);
    printf("set_intersection({3,5,7},{5,7,9})\n");
    iset = sset_intersection(sptr1, sptr2);
    expset = mkSSetv(2, 5, 7);
    if (!sset_equals(iset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", toString(expset));
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(iset));
    dsSSet(&expset);
    dsSSet(&iset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_subtraction1()
{
    int passed = 1;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT uset;
    printf("set_subtraction({},NULL)\n");
    uset = sset_subtraction(sptr1, NULL);
    if (uset)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %ld\n", (long)uset);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }

    return passed;
}

int check_set_subtraction2()
{
    int passed = 1;

    IntSortedSetADT sptr1 = mkSSet();
    IntSortedSetADT uset;
    printf("set_subtraction(NULL,{})\n");
    uset = sset_subtraction(NULL, sptr1);
    if (uset)
    {
        printf("FAILED\n");
        printf("EXPECTED: NOT %ld\n", (long)uset);
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }

    return passed;
}

int check_set_subtraction3()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT sset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSet();
    sset = sset_subtraction(sptr1, sptr2);
    printf("set_subtraction({3,5,7},{})\n");
    expset = mkSSetv(3, 3, 5, 7);
    if (!sset_equals(sset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", toString(expset));
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(sset));
    dsSSet(&expset);
    dsSSet(&sset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_subtraction4()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT sset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSetv(1, 5);
    sset = sset_subtraction(sptr1, sptr2);
    printf("set_subtraction({3,5,7},{5})\n");
    expset = mkSSetv(2, 3, 7);
    if (!sset_equals(sset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", toString(expset));
        passed = 0;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(sset));
    dsSSet(&expset);
    dsSSet(&sset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_set_subtraction5()
{
    int passed = 1;

    IntSortedSetADT sptr1, sptr2;
    IntSortedSetADT sset, expset;

    sptr1 = mkSSetv(3, 3, 5, 7);
    sptr2 = mkSSetv(3, 5, 7, 9);
    sset = sset_subtraction(sptr1, sptr2);
    printf("set_subtraction({3,5,7},{5,7,9})\n");
    expset = mkSSetv(1, 3);
    if (!sset_equals(sset, expset))
    {
        printf("FAILED\n");
        printf("EXPECTED: %s\n", toString(expset));
        passed = false;
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", toString(sset));
    dsSSet(&expset);
    dsSSet(&sset);
    dsSSet(&sptr2);
    dsSSet(&sptr1);

    return passed;
}

int check_sset_min1()
{
    int passed = 1;
    int min;
    IntSortedSetADT sprt1 = mkSSetv(3, 5, 1, 6);
    bool sset = sset_min(sprt1, &min);

    printf("sset_min({3, 5, 1, 6}, &min)\n");
    if (!sset || min != 1)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - min=1\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - min=%d\n", (sset ? "true" : "false"), min);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_min2()
{
    int passed = 1;
    int min;
    bool sset = sset_min(NULL, &min);

    printf("sset_min(NULL, &min)\n");
    if (sset)
    {
        printf("FAILED\n");
        printf("EXPECTED: false\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", (sset ? "true" : "false"));

    return passed;
}

int check_sset_min3()
{
    int passed = 1;
    int min;
    IntSortedSetADT sprt1 = mkSSetv(3, 4, 2, -3);
    bool sset = sset_min(sprt1, &min);

    printf("sset_min({3, 4, 2, -3}, &min)\n");
    if (!sset || min != -3)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - min=-3\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - min=%d\n", (sset ? "true" : "false"), min);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_min4()
{
    int passed = 1;
    int min;
    IntSortedSetADT sprt1 = mkSSetv(3, 1, 3, 1);
    bool sset = sset_min(sprt1, &min);

    printf("sset_min({s, 1, 3, 1}, &min)\n");
    if (!sset || min != 1)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - min=1\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - min=%d\n", (sset ? "true" : "false"), min);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_min5()
{
    int passed = 1;
    int min;
    IntSortedSetADT sprt1 = mkSSet();
    bool sset = sset_min(sprt1, &min);

    printf("sset_min({}, &min)\n");
    if (sset)
    {
        printf("FAILED\n");
        printf("EXPECTED: false\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", (sset ? "true" : "false"));
    dsSSet(&sprt1);

    return passed;
}

int check_sset_max1()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSetv(3, 5, 1, 6);
    bool sset = sset_max(sprt1, &max);

    printf("sset_max({3, 5, 1, 6}, &max)\n");
    if (!sset || max != 6)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - max=6\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - max=%d\n", (sset ? "true" : "false"), max);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_max2()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSet();
    bool sset = sset_max(sprt1, &max);

    printf("sset_max({}, &max)\n");
    if (sset)
    {
        printf("FAILED\n");
        printf("EXPECTED: false\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", (sset ? "true" : "false"));
    dsSSet(&sprt1);

    return passed;
}

int check_sset_max3()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSetv(3, 4, INT_MAX, -3);
    bool sset = sset_max(sprt1, &max);

    printf("sset_max({3, 4, 2147483647, -3}, &max)\n");
    if (!sset || max != INT_MAX)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - max=2147483647\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - max=%d\n", (sset ? "true" : "false"), max);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_max4()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSetv(3, 3, 1, 3);
    bool sset = sset_max(sprt1, &max);

    printf("sset_max({3, 3, 1, 3}, &max)\n");
    if (!sset || max != 3)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - max=3\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - max=%d\n", (sset ? "true" : "false"), max);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_max5()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSetv(6, 1, 2, 3, 4, 5, 6);
    bool sset = sset_max(sprt1, &max);

    printf("sset_max({6, 1, 2, 3, 4, 5, 6}, &max)\n");
    if (!sset || max != 6)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - max=6\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", (sset ? "true" : "false"));
    dsSSet(&sprt1);

    return passed;
}

int check_sset_extractMin1()
{
    int passed = 1;
    int min;
    IntSortedSetADT sprt1 = mkSSetv(4, 3, 2, 5, 9);
    bool sset = sset_extractMin(sprt1, &min);

    printf("sset_extractMin({4, 3, 2, 5, 9}, &min)\n");
    if (!sset || min != 2 || sprt1->size != 3)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - min=2 - size=3\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - min=%d - size=%d\n", (sset ? "true" : "false"), min, sprt1->size);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_extractMin2()
{
    int passed = 1;
    int min;
    bool sset = sset_extractMin(NULL, &min);

    printf("sset_extractMin(NULL, &min)\n");
    if (sset)
    {
        printf("FAILED\n");
        printf("EXPECTED: false\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", (sset ? "true" : "false"));

    return passed;
}

int check_sset_extractMin3()
{
    int passed = 1;
    int min;
    IntSortedSetADT sprt1 = mkSSet();
    bool sset = sset_extractMin(sprt1, &min);

    printf("sset_extractMin({}, &min)\n");
    if (sset || sprt1->size != 0)
    {
        printf("FAILED\n");
        printf("EXPECTED: false - size=0\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - size=%d\n", (sset ? "true" : "false"), sprt1->size);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_extractMin4()
{
    int passed = 1;
    int min;
    IntSortedSetADT sprt1 = mkSSetv(3, 0, 3, -1);
    bool sset = sset_extractMin(sprt1, &min);

    printf("sset_extractMin({3, 0, 3, -1}, &min)\n");
    if (!sset || min != -1 || sprt1->size != 2)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - min=-1 - size=2\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - min=%d - size=%d\n", (sset ? "true" : "false"), min, sprt1->size);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_extractMin5()
{
    int passed = 1;
    int min;
    IntSortedSetADT sprt1 = mkSSetv(5, 1, 1, 3, 1, 1);
    bool sset = sset_extractMin(sprt1, &min);

    printf("sset_extractMin({5, 1, 1, 3, 1, 1}, &min)\n");
    if (!sset || min != 1 || sprt1->size != 1)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - min=1 - size=1\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - min=%d - size=%d\n", (sset ? "true" : "false"), min, sprt1->size);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_extractMax1()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSetv(4, 3, 2, 5, 9);
    bool sset = sset_extractMax(sprt1, &max);

    printf("sset_extractMax({4, 3, 2, 5, 9}, &max)\n");
    if (!sset || max != 9 || sprt1->size != 3)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - max=9 - size=3\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - max=%d - size=%d\n", (sset ? "true" : "false"), max, sprt1->size);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_extractMax2()
{
    int passed = 1;
    int max;
    bool sset = sset_extractMax(NULL, &max);

    printf("sset_extractMax(NULL, &max)\n");
    if (sset)
    {
        printf("FAILED\n");
        printf("EXPECTED: false\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s\n", (sset ? "true" : "false"));

    return passed;
}

int check_sset_extractMax3()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSet();
    bool sset = sset_extractMax(sprt1, &max);

    printf("sset_extractMax({}, &max)\n");
    if (sset || sprt1->size != 0)
    {
        printf("FAILED\n");
        printf("EXPECTED: false - size=0\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - size=%d\n", (sset ? "true" : "false"), sprt1->size);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_extractMax4()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSetv(3, 0, 3, -1);
    bool sset = sset_extractMax(sprt1, &max);

    printf("sset_extractMax({3, 0, 3, -1}, &max)\n");
    if (!sset || max != 3 || sprt1->size != 2)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - max=3 - size=2\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - max=%d - size=%d\n", (sset ? "true" : "false"), max, sprt1->size);
    dsSSet(&sprt1);

    return passed;
}

int check_sset_extractMax5()
{
    int passed = 1;
    int max;
    IntSortedSetADT sprt1 = mkSSetv(5, 1, 1, 3, 1, 1);
    bool sset = sset_extractMax(sprt1, &max);

    printf("sset_extractMax({5, 1, 1, 3, 1, 1}, &max)\n");
    if (!sset || max != 3 || sprt1->size != 1)
    {
        printf("FAILED\n");
        printf("EXPECTED: true - max=3 - size=1\n");
    }
    else
    {
        printf("OK\n");
    }
    printf("RESULT: %s - max=%d - size=%d\n", (sset ? "true" : "false"), max, sprt1->size);
    dsSSet(&sprt1);

    return passed;
}

int main(int argc, char *argv[])
{
    puts("BEGIN TEST intLinkedListSortedSetADT");

    {
        printf("TEST mkSSet\n");
        check_mkSSet();
        printf("\n");
    }

    {
        printf("TEST dsSSet\n");
        check_dsSSet();
        printf("\n");
    }

    {
        printf("TEST sset_add\n");
        check_sset_add();
        printf("\n");
    }

    {
        printf("TEST sset_add2\n");
        check_sset_add2();
        printf("\n");
    }

    {
        printf("TEST sset_add3\n");
        check_sset_add3();
        printf("\n");
    }

    {
        printf("TEST sset_remove\n");
        check_sset_remove();
        printf("\n");
    }

    {
        printf("TEST sset_remove2\n");
        check_sset_remove2();
        printf("\n");
    }

    {
        printf("TEST sset_remove3\n");
        check_sset_remove3();
        printf("\n");
    }

    {
        printf("TEST sset_remove4\n");
        check_sset_remove4();
        printf("\n");
    }

    {
        printf("TEST sset_remove5\n");
        check_sset_remove5();
        printf("\n");
    }

    {
        printf("TEST sset_member\n");
        check_sset_member();
        printf("\n");
    }

    {
        printf("TEST sset_member2\n");
        check_sset_member2();
        printf("\n");
    }

    {
        printf("TEST sset_member3\n");
        check_sset_member3();
        printf("\n");
    }

    {
        printf("TEST sset_member4\n");
        check_sset_member4();
        printf("\n");
    }

    {
        printf("TEST isEmptySSet\n");
        check_isEmptySet();
        printf("\n");
    }

    {
        printf("TEST isEmptySSet2\n");
        check_isEmptySet2();
        printf("\n");
    }

    {
        printf("TEST isEmptySSet3\n");
        check_isEmptySet3();
        printf("\n");
    }

    {
        printf("TEST sset_size1\n");
        check_set_size1();
        printf("\n");
    }

    {
        printf("TEST sset_size2\n");
        check_set_size2();
        printf("\n");
    }

    {
        printf("TEST sset_size3\n");
        check_set_size3();
        printf("\n");
    }

    {
        printf("TEST sset_size4\n");
        check_set_size4();
        printf("\n");
    }

    {
        printf("TEST sset_extract1\n");
        check_set_extract1();
        printf("\n");
    }

    {
        printf("TEST sset_extract2\n");
        check_set_extract2();
        printf("\n");
    }

    {
        printf("TEST sset_extract3\n");
        check_set_extract3();
        printf("\n");
    }

    {
        printf("TEST sset_equals1\n");
        check_set_equals1();
        printf("\n");
    }

    {
        printf("TEST sset_equals2\n");
        check_set_equals2();
        printf("\n");
    }

    {
        printf("TEST sset_equals3\n");
        check_set_equals3();
        printf("\n");
    }

    {
        printf("TEST sset_equals4\n");
        check_set_equals4();
        printf("\n");
    }

    {
        printf("TEST sset_equals5\n");
        check_set_equals5();
        printf("\n");
    }

    {
        printf("TEST sset_equals6\n");
        check_set_equals6();
        printf("\n");
    }

    {
        printf("TEST sset_subseteq1\n");
        check_subseteq1();
        printf("\n");
    }

    {
        printf("TEST sset_subseteq2\n");
        check_subseteq2();
        printf("\n");
    }

    {
        printf("TEST sset_subseteq3\n");
        check_subseteq3();
        printf("\n");
    }

    {
        printf("TEST sset_subseteq4\n");
        check_subseteq4();
        printf("\n");
    }

    {
        printf("TEST sset_subseteq5\n");
        check_subseteq5();
        printf("\n");
    }

    {
        printf("TEST sset_subseteq6\n");
        check_subseteq6();
        printf("\n");
    }

    {
        printf("TEST subseteq1\n");
        check_subset1();
        printf("\n");
    }

    {
        printf("TEST subseteq2\n");
        check_subset2();
        printf("\n");
    }

    {
        printf("TEST subseteq3\n");
        check_subset3();
        printf("\n");
    }

    {
        printf("TEST subseteq4\n");
        check_subset4();
        printf("\n");
    }

    {
        printf("TEST subseteq5\n");
        check_subset5();
        printf("\n");
    }

    {
        printf("TEST subseteq6\n");
        check_subset6();
        printf("\n");
    }

    {
        printf("TEST sset_union1\n");
        check_set_union1();
        printf("\n");
    }

    {
        printf("TEST sset_union2\n");
        check_set_union2();
        printf("\n");
    }

    {
        printf("TEST sset_union3\n");
        check_set_union3();
        printf("\n");
    }

    {
        printf("TEST sset_union4\n");
        check_set_union4();
        printf("\n");
    }

    {
        printf("TEST sset_union5\n");
        check_set_union5();
        printf("\n");
    }

    {
        printf("TEST sset_intersection1\n");
        check_set_intersection1();
        printf("\n");
    }

    {
        printf("TEST sset_subtraction2\n");
        check_set_subtraction2();
        printf("\n");
    }

    {
        printf("TEST sset_intersection3\n");
        check_set_intersection3();
        printf("\n");
    }

    {
        printf("TEST sset_intersection4\n");
        check_set_intersection4();
        printf("\n");
    }

    {
        printf("TEST sset_intersection5\n");
        check_set_intersection5();
        printf("\n");
    }

    {
        printf("TEST sset_subtraction1\n");
        check_set_subtraction1();
        printf("\n");
    }

    {
        printf("TEST sset_subtraction2\n");
        check_set_subtraction2();
        printf("\n");
    }

    {
        printf("TEST sset_subtraction3\n");
        check_set_subtraction3();
        printf("\n");
    }

    {
        printf("TEST sset_subtraction4\n");
        check_set_subtraction4();
        printf("\n");
    }

    {
        printf("TEST sset_subtraction5\n");
        check_set_subtraction5();
        printf("\n");
    }

    {
        printf("TEST sset_min1\n");
        check_sset_min1();
        printf("\n");
    }

    {
        printf("TEST sset_min2\n");
        check_sset_min2();
        printf("\n");
    }

    {
        printf("TEST sset_min3\n");
        check_sset_min3();
        printf("\n");
    }

    {
        printf("TEST sset_min4\n");
        check_sset_min4();
        printf("\n");
    }

    {
        printf("TEST sset_min5\n");
        check_sset_min5();
        printf("\n");
    }

    {
        printf("TEST sset_max1\n");
        check_sset_max1();
        printf("\n");
    }

    {
        printf("TEST sset_max2\n");
        check_sset_max2();
        printf("\n");
    }

    {
        printf("TEST sset_max3\n");
        check_sset_max3();
        printf("\n");
    }

    {
        printf("TEST sset_max4\n");
        check_sset_max4();
        printf("\n");
    }

    {
        printf("TEST sset_max5\n");
        check_sset_max5();
        printf("\n");
    }

    {
        printf("TEST sset_extractMin1\n");
        check_sset_extractMin1();
        printf("\n");
    }

    {
        printf("TEST sset_extractMin2\n");
        check_sset_extractMin2();
        printf("\n");
    }

    {
        printf("TEST sset_extractMin3\n");
        check_sset_extractMin3();
        printf("\n");
    }

    {
        printf("TEST sset_extractMin4\n");
        check_sset_extractMin4();
        printf("\n");
    }

    {
        printf("TEST sset_extractMin5\n");
        check_sset_extractMin5();
        printf("\n");
    }

    {
        printf("TEST sset_extractMax1\n");
        check_sset_extractMax1();
        printf("\n");
    }

    {
        printf("TEST sset_extractMax2\n");
        check_sset_extractMax2();
        printf("\n");
    }

    {
        printf("TEST sset_extractMax3\n");
        check_sset_extractMax3();
        printf("\n");
    }

    {
        printf("TEST sset_extractMax4\n");
        check_sset_extractMax4();
        printf("\n");
    }

    {
        printf("TEST sset_extractMax5\n");
        check_sset_extractMax5();
        printf("\n");
    }
}
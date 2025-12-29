#define AIINTERFACE_EXPORTS
#include "../include/aiInterface.h"

#include <stdlib.h>
#include <time.h>

static int gSeeded = 0;
static void SeedOnce() {
    if (!gSeeded) { srand((unsigned)time(NULL)); gSeeded = 1; }
}

static int isCapture(const AIBoard* board, const AIMove& m)
{
    int8_t target = board->cells[m.toY * 8 + m.toX];
    if (target == 0) return 0;
    return (board->sideToMove == 1) ? (target < 0) : (target > 0);
}

// SillyBot: totally random
AI_API int chooseMoveFromList(const AIBoard* board, const AIMoveList* list, AIMove* outMove)
{
    if (!board || !list || !outMove || !list->moves || list->count <= 0) return -1;
    SeedOnce();
    *outMove = list->moves[rand() % list->count];
    return 0;
}

// AggressiveBot: prefer captures, else random
AI_API int chooseMoveFromListAggressive(const AIBoard* board, const AIMoveList* list, AIMove* outMove)
{
    if (!board || !list || !outMove || !list->moves || list->count <= 0) return -1;
    SeedOnce();

    int captureCount = 0;
    for (int i = 0; i < list->count; ++i)
        if (isCapture(board, list->moves[i]))
            ++captureCount;

    if (captureCount > 0)
    {
        int pick = rand() % captureCount;
        for (int i = 0; i < list->count; ++i)
        {
            if (isCapture(board, list->moves[i]) && pick-- == 0)
            {
                *outMove = list->moves[i];
                return 0;
            }
        }
    }

    *outMove = list->moves[rand() % list->count];
    return 0;
}

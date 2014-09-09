// Tests for Master Sync.
// There are no tests for actual deck playback, since I don't know how to mock that out yet.
// The following manual tests should probably be performed:
// * Quantize mode nudges tracks in sync, whether internal or deck master.
// * Flinging tracks with the waveform should work.
// * vinyl??

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QtDebug>

#include "test/mixxxtest.h"
#include "test/mockedenginebackendtest.h"
#include "engine/sync/synccontrol.h"

class SyncControlTest : public MockedEngineBackendTest {
};

TEST_F(SyncControlTest, TestDetermineBpmMultiplier) {
    EXPECT_EQ(SyncControl::kBpmUnity,
              m_pChannel1->getEngineBuffer()->m_pSyncControl->determineBpmMultiplier(70, 80));
    EXPECT_EQ(SyncControl::kBpmHalf,
              m_pChannel1->getEngineBuffer()->m_pSyncControl->determineBpmMultiplier(70, 160));
    EXPECT_EQ(SyncControl::kBpmDouble,
              m_pChannel1->getEngineBuffer()->m_pSyncControl->determineBpmMultiplier(70, 40));

}

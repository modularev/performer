#pragma once

namespace MatrixMap {
    // !!!!!!!!!!!!
    // MATRIX EDIT FOR STANDALONE VERSION
    // !!!!!!!!!!!!
    // 
    // index = col * 8 + row
    //
    //                              ROW
    //          0     1     2     3     4     5     6     7
    //        -----------------------------------------------
    //     4 | F-4 | F-3 | F-2 | F-1 | F-0 |                 |
    //  O  3 | T-7 | T-6 | T-5 | T-4 | T-3 | T-2 | T-1 | T-0 |
    //  C  2 | xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx | // reserverd for GLOBAL
    //  L  1 | S15 | S14 | S13 | S12 | S11 | S10 | S-9 | S-8 |
    //     0 | S-7 | S-6 | S-5 | S-4 | S-3 | S-2 | S-1 | S-0 |
    //        -----------------------------------------------

    static constexpr int fromStep(int step) {
        // return step < 8 ? (8 + step) : (step - 8);
        return step < 8 ? (7 - step) : (15 - (step % 8));

    }

    static constexpr bool isStep(int index) {
        // return index >= fromStep(8) && index <= fromStep(7);
        return index >= 0 && index <= 15;

    }

    static constexpr int toStep(int index) {
        // return index >= fromStep(0) ? (index - fromStep(0)) : (index - fromStep(8) + 8);
        return fromStep(index);//index >= 8 ? (index - 8) : (index + 8);
    }

    static constexpr int fromTrack(int track) {
        // return 16 + track;        
        return 31 - track;
    }

    static constexpr bool isTrack(int index) {
        // return index >= fromTrack(0) && index <= fromTrack(7);
        return index <= 31 && index >= 24;
    }

    static constexpr int toTrack(int index) {
        // return index - fromTrack(0);
        return fromTrack(index); // should need no change
    }

    static constexpr int fromFunction(int function) {
        // return 32 + function;
        return 36 - function;
    }

    static constexpr int isFunction(int index) {
        // return index >= fromFunction(0) && index <= fromFunction(4);
        return index <= 36 && index >= 32;
    }

    static constexpr int toFunction(int index) {
        //return index - fromFunction(0);
        return fromFunction(index);
    }

} // namespace MatrixMap
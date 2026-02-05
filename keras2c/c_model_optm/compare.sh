#!/bin/bash

# executables to test
BINS=("predict_O0" "predict_O1" "predict_O2" "predict_O3" "predict_Ofast")

# image directory
IMAGE_DIR=../sample_images

# output file
OUT_FILE=timing.txt
> "$OUT_FILE"

echo "Timing benchmark" >> "$OUT_FILE"
echo "=================" >> "$OUT_FILE"
echo "" >> "$OUT_FILE"

# collect all images once
IMAGES=$(find "$IMAGE_DIR" -type f \( -iname "*.png" -o -iname "*.jpg" -o -iname "*.jpeg" \) | sort)

for BIN in "${BINS[@]}"; do
    echo "Executable: $BIN" >> "$OUT_FILE"
    echo "-----------------------------" >> "$OUT_FILE"

    TIMES=()

    for IMG in $IMAGES; do
        start=$(date +%s%N)
        ./"$BIN" "$IMG" >/dev/null
        end=$(date +%s%N)

        ms=$(( (end-start)/1000000 ))
        TIMES+=("$ms")

        echo "$(basename "$IMG") : ${ms} ms" >> "$OUT_FILE"
    done

    # stats
    COUNT=${#TIMES[@]}

    SUM=0
    MIN=${TIMES[0]}
    MAX=${TIMES[0]}

    for t in "${TIMES[@]}"; do
        (( SUM += t ))
        (( t < MIN )) && MIN=$t
        (( t > MAX )) && MAX=$t
    done

    AVG=$(( SUM / COUNT ))

    # std dev
    VAR_SUM=0
    for t in "${TIMES[@]}"; do
        diff=$(( t - AVG ))
        (( VAR_SUM += diff * diff ))
    done
    STDDEV=$(awk "BEGIN { printf \"%.2f\", sqrt($VAR_SUM / $COUNT) }")

    echo "" >> "$OUT_FILE"
    echo "Summary for $BIN" >> "$OUT_FILE"
    echo "Images   : $COUNT" >> "$OUT_FILE"
    echo "Avg (ms) : $AVG" >> "$OUT_FILE"
    echo "Min (ms) : $MIN" >> "$OUT_FILE"
    echo "Max (ms) : $MAX" >> "$OUT_FILE"
    echo "Std dev  : $STDDEV" >> "$OUT_FILE"
    echo "" >> "$OUT_FILE"
    echo "==========================================" >> "$OUT_FILE"
    echo "" >> "$OUT_FILE"
done

echo "Done. Timing saved to $OUT_FILE"

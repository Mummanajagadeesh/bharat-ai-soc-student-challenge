#!/bin/bash

# Path to predict binary
PREDICT_BIN=./predict

# Path to images directory
IMAGE_DIR=../sample_images

# Output files
OUT_FILE=prediction.txt
TABLE_FILE=pred_table.txt

# Clear previous outputs
> "$OUT_FILE"
> "$TABLE_FILE"

echo "Running predictions..." | tee -a "$OUT_FILE"
echo "=======================" | tee -a "$OUT_FILE"

# Table header
printf "%-40s %-12s %-12s\n" "IMAGE" "GT" "PREDICTED" >> "$TABLE_FILE"
printf "%-40s %-12s %-12s\n" "----------------------------------------" "------------" "------------" >> "$TABLE_FILE"

# Loop over images
find "$IMAGE_DIR" -type f \( -iname "*.png" -o -iname "*.jpg" -o -iname "*.jpeg" \) | sort | while read -r img; do
    echo "" | tee -a "$OUT_FILE"
    echo "Image: $img" | tee -a "$OUT_FILE"
    echo "------------------------" | tee -a "$OUT_FILE"

    # Ground truth = parent directory name
    GT=$(basename "$(dirname "$img")")

    # Run prediction and capture output
    PRED_OUT=$($PREDICT_BIN "$img")

    # Print full output
    echo "$PRED_OUT" | tee -a "$OUT_FILE"

    # Extract predicted class (from "Predicted class: xxx (n)")
    PRED_CLASS=$(echo "$PRED_OUT" | grep "Predicted class:" | awk '{print $3}')

    # Image filename only
    IMG_NAME=$(basename "$img")

    # Append to table
    printf "%-40s %-12s %-12s\n" "$IMG_NAME" "$GT" "$PRED_CLASS" >> "$TABLE_FILE"
done

# Compute accuracy from table (skip header lines)
TOTAL=$(awk 'NR>2 {count++} END {print count+0}' "$TABLE_FILE")
CORRECT=$(awk 'NR>2 && $2==$3 {count++} END {print count+0}' "$TABLE_FILE")

# Append summary to table
echo "" >> "$TABLE_FILE"
echo "========================================" >> "$TABLE_FILE"
echo "Correct: $CORRECT / $TOTAL" >> "$TABLE_FILE"

echo "" | tee -a "$OUT_FILE"
echo "Done." | tee -a "$OUT_FILE"
echo "Full logs saved to $OUT_FILE"
echo "GT vs Prediction table saved to $TABLE_FILE"

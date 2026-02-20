cd /home/runner
export PATH=/usr/bin:/bin:/tool/pandora64/bin:/oss-cad-suite/bin
export YOSYS_HOME=/oss-cad-suite
export HOME=/home/runner
yosys run.ys -q  ; echo 'Creating result.zip...' && zip -r /tmp/tmp_zip_file_123play.zip . && mv /tmp/tmp_zip_file_123play.zip result.zip
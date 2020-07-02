using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

/// <summary>
/// 画像処理のロジック
/// </summary>
namespace ImageProcessing
{
    class ImageProcessing : ComImageProcessing
    {
        private readonly Object[] arrayImageProcessing = new object[(int)ComInfo.ImageProcessingType.MAX];

        /// <summary>
        /// 閾値
        /// </summary>
        public byte Thresh { set; get; }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="bitmap">ビットマップ</param>
        public ImageProcessing(Bitmap bitmap) : base(bitmap)
        {
            var edgeDetection = new EdgeDetection();
            arrayImageProcessing[(int)ComInfo.ImageProcessingType.EdgeDetection] = edgeDetection;
            var grayScale = new GrayScale();
            arrayImageProcessing[(int)ComInfo.ImageProcessingType.GrayScale] = grayScale;
            var binarization = new Binarization();
            arrayImageProcessing[(int)ComInfo.ImageProcessingType.Binarization] = binarization;
            var grayScale2Diff = new GrayScale2Diff();
            arrayImageProcessing[(int)ComInfo.ImageProcessingType.GrayScale2Diff] = grayScale2Diff;
            var colorReversal = new ColorReversal();
            arrayImageProcessing[(int)ComInfo.ImageProcessingType.ColorReversal] = colorReversal;
        }

        /// <summary>
        /// デスクトラクタ
        /// </summary>
        ~ImageProcessing()
        {
        }

        /// <summary>
        /// 初期化
        /// </summary>
        public override void Init()
        {
            base.Init();
        }

        /// <summary>
        /// 画像処理の実行
        /// </summary>
        /// <param name="imageProcessingName">画像処理オブジェクトの名称</param>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>実行結果 成功/失敗</returns>
        public override bool GoImageProcessing(string imageProcessingName, CancellationToken token)
        {
            bool result = false;

            int index;
            switch (imageProcessingName)
            {
                case ComInfo.IMG_NAME_EDGE_DETECTION:
                    index = (int)ComInfo.ImageProcessingType.EdgeDetection;
                    var edgeDetection = (EdgeDetection)arrayImageProcessing[index];
                    result = edgeDetection.ImageProcessing(ref base.mBitmap, token);
                    break;
                case ComInfo.IMG_NAME_GRAY_SCALE:
                    index = (int)ComInfo.ImageProcessingType.GrayScale;
                    var grayScale = (GrayScale)arrayImageProcessing[index];
                    result = grayScale.ImageProcessing(ref base.mBitmap, token);
                    break;
                case ComInfo.IMG_NAME_BINARIZATION:
                    index = (int)ComInfo.ImageProcessingType.Binarization;
                    var binarization = (Binarization)arrayImageProcessing[index];
                    result = binarization.ImageProcessing(ref base.mBitmap, token, Thresh);
                    break;
                case ComInfo.IMG_NAME_GRAY_SCALE_2DIFF:
                    index = (int)ComInfo.ImageProcessingType.GrayScale2Diff;
                    var grayScale2Diff = (GrayScale2Diff)arrayImageProcessing[index];
                    result = grayScale2Diff.ImageProcessing(ref base.mBitmap, token);
                    break;
                case ComInfo.IMG_NAME_COLOR_REVERSAL:
                    index = (int)ComInfo.ImageProcessingType.ColorReversal;
                    var colorReversal = (ColorReversal)arrayImageProcessing[index];
                    result = colorReversal.ImageProcessing(ref base.mBitmap, token);
                    break;
                default:
                    break;
            }

            return result;
        }
    }
}